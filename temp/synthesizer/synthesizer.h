#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

//some macros
#define CLAMP(value,min,max) {if(value  max) { value = max; }}
 
 //0 to 255
void ConvertFloatToAudioSample(float fFloat, uint8_t &nOut)
{
    fFloat = (fFloat + 1.0f) * 127.5f;
    CLAMP(fFloat,0.0f,255.0f);
    nOut = (uint8_t)fFloat;
}
 
//–32,768 to 32,767
void ConvertFloatToAudioSample(float fFloat, int16_t &nOut)
{
    fFloat *= 32767.0f;
    CLAMP(fFloat,-32768.0f,32767.0f);
    nOut = (int16_t)fFloat;
}
 
//–2,147,483,648 to 2,147,483,647
void ConvertFloatToAudioSample(float fFloat, int32_t &nOut)
{
    double dDouble = (double)fFloat;
    dDouble *= 2147483647.0;
    CLAMP(dDouble,-2147483648.0,2147483647.0);
    nOut = (int32_t)dDouble;
}
 
//calculate the frequency of the specified note.
//fractional notes allowed!
float CalcFrequency(float fOctave,float fNote)
/*
    Calculate the frequency of any note!
    frequency = 440×(2^(n/12))
 
    N=0 is A4
    N=1 is A#4
    etc...
 
    notes go like so...
    0  = A
    1  = A#
    2  = B
    3  = C
    4  = C#
    5  = D
    6  = D#
    7  = E
    8  = F
    9  = F#
    10 = G
    11 = G#
*/
{
    return (float)(440*pow(2.0,((double)((fOctave-4)*12+fNote))/12.0));
}

//this struct is the minimal required header data for a wav file
struct SMinimalWaveFileHeader{
	//the main chunk
	unsigned char m_szChunkID[4];
	uint32_t m_nChunkSize;
	unsigned char m_szFormat[4];

	//sub chunk 1 "fmt "
	unsigned char m_szSubChunk1ID[4];
	uint32_t m_nSubChunk1Size;
	uint16_t m_nAudioFormat;
	uint16_t m_nNumChannels;
	uint32_t m_nSampleRate;
	uint32_t m_nByteRate;
	uint16_t m_nBlockAlign;
	uint16_t m_nBitsPerSample;

	//sub chunk 2 "data"
	unsigned char m_szSubChunk2ID[4];
	uint32_t m_nSubChunk2Size;

	//then comes the data!
};


// here’s the function that fills out the struct and writes it to disk:
bool WriteWaveFile(const char *szFileName, 
                   void *pData, 
                   int32_t nDataSize, 
                   int16_t nNumChannels, 
                   int32_t nSampleRate, 
                   int32_t nBitsPerSample){

	//open the file if we can
	FILE *File = fopen(szFileName,"w+b");

	if(!File)
		return false;

	SMinimalWaveFileHeader waveHeader;

	//fill out the main chunk
	memcpy(waveHeader.m_szChunkID,"RIFF",4);
	waveHeader.m_nChunkSize = nDataSize + 36;
	memcpy(waveHeader.m_szFormat,"WAVE",4);

	//fill out sub chunk 1 "fmt "
	memcpy(waveHeader.m_szSubChunk1ID,"fmt ",4);
	waveHeader.m_nSubChunk1Size = 16;
	waveHeader.m_nAudioFormat = 1;
	waveHeader.m_nNumChannels = nNumChannels;
	waveHeader.m_nSampleRate = nSampleRate;
	waveHeader.m_nByteRate = nSampleRate * nNumChannels * nBitsPerSample / 8;
	waveHeader.m_nBlockAlign = nNumChannels * nBitsPerSample / 8;
	waveHeader.m_nBitsPerSample = nBitsPerSample;

	//fill out sub chunk 2 "data"
	memcpy(waveHeader.m_szSubChunk2ID,"data",4);
	waveHeader.m_nSubChunk2Size = nDataSize;

	//write the header
	fwrite(&waveHeader,sizeof(SMinimalWaveFileHeader),1,File);

	//write the wave data itself
	fwrite(pData,nDataSize,1,File);

	//close the file and return success
	fclose(File);
	return true;
}

// modified WriteWaveFile
//this writes a wave file
//specify sample bit count as the template parameter
//can be uint8, int16 or int32
template
bool WriteWaveFile2(const char *szFileName, float *pRawData, int32 nNumSamples, int16 nNumChannels, int32 nSampleRate)
{
    //open the file if we can
    FILE *File = fopen(szFileName,"w+b");
    if(!File)
    {
        return false;
    }
 
    //calculate bits per sample and the data size
    int32_t nBitsPerSample = sizeof(T) * 8;
    int nDataSize = nNumSamples * sizeof(T);
 
    SMinimalWaveFileHeader waveHeader;
 
    //fill out the main chunk
    memcpy(waveHeader.m_szChunkID,"RIFF",4);
    waveHeader.m_nChunkSize = nDataSize + 36;
    memcpy(waveHeader.m_szFormat,"WAVE",4);
 
    //fill out sub chunk 1 "fmt "
    memcpy(waveHeader.m_szSubChunk1ID,"fmt ",4);
    waveHeader.m_nSubChunk1Size = 16;
    waveHeader.m_nAudioFormat = 1;
    waveHeader.m_nNumChannels = nNumChannels;
    waveHeader.m_nSampleRate = nSampleRate;
    waveHeader.m_nByteRate = nSampleRate * nNumChannels * nBitsPerSample / 8;
    waveHeader.m_nBlockAlign = nNumChannels * nBitsPerSample / 8;
    waveHeader.m_nBitsPerSample = nBitsPerSample;
 
    //fill out sub chunk 2 "data"
    memcpy(waveHeader.m_szSubChunk2ID,"data",4);
    waveHeader.m_nSubChunk2Size = nDataSize;
 
    //write the header
    fwrite(&waveHeader,sizeof(SMinimalWaveFileHeader),1,File);
 
    //write the wave data itself, converting it from float to the type specified
    T *pData = new T[nNumSamples];
    for(int nIndex = 0; nIndex = 2 * (float)M_PI)
        fPhase -= 2 * (float)M_PI;
 
    while(fPhase  1.0f)
        fPhase -= 1.0f;
 
    while(fPhase  1.0f)
        fPhase -= 1.0f;
 
    while(fPhase < 0.0f)
        fPhase += 1.0f;
 
    if(fPhase  1.0f)
        fPhase -= 1.0f;
 
    while(fPhase < 0.0f)
        fPhase += 1.0f;
 
    float fRet;
    if(fPhase  2.0f)
        fPhase -= 1.0f;
 
    if(nSeed != nLastSeed)
    {
        float fValue = ((float)rand()) / ((float)RAND_MAX);
        fValue = (fValue * 2.0f) - 1.0f;
 
        //uncomment the below to make it slightly more intense
        /*
        if(fValue < 0)
            fValue = -1.0f;
        else
            fValue = 1.0f;
        */
 
        return fValue;
    }
    else
    {
        return fLastValue;
    }
}

#endif