#include "synthesizer.h"


int main(){

    /*-------- SAW TOOTH WAVE --------------------*/

    // generate some audio data and make a real wave file!
    int nSampleRate = 44100; //The sample rate defines how many samples of audio data there are per second.
    int nNumSeconds = 4; //The number of seconds is how long (in seconds) the wave goes on for
    int nNumChannels = 1; //the number of channels is how many audio channels there are

    /* generating mono audio */

    //calculate how many actual audio samples there are
    int nNumSamples = nSampleRate * nNumChannels * nNumSeconds; 

    //allocate space to hold the audio data
    int32_t *pDataMono = new int32_t[nNumSamples]; 
    // We are using 32 bit integers
    // The number of bits in your audio samples indicates the vertical resolution of your audio data, 
    // or how many unique values there are


    // creating our wave data.
    int32_t nValue = 0;
    for(int nIndex = 0; nIndex < nNumSamples; ++nIndex){
	    nValue += 8000000;
        // We are using the fact that if you have an int near the maximum value you can store, 
        // and then add some more, it will wrap around to the minimum value the int can store. 
        // you can change how much is added to nValue to change the frequency of the resulting wave.
        // Add a smaller number to make it a lower frequency, 
        // add a higher number to make it a higher frequency. 
	    pDataMono[nIndex] = nValue;
    };

    WriteWaveFile("outmono.wav",pDataMono,nNumSamples * sizeof(pDataMono[0]),nNumChannels,nSampleRate,sizeof(pDataMono[0])*8);
    delete[] pDataMono;



    /*  Writing a Stereo File */
    // The only thing that has really changed in the stereo file is that there are 2 channels instead of 1
    // Since there are 2 channels, one for left, one for right, there is actually double the audio data for 
    // the same sample rate and time length wave file, since it needs a full set of data for each channel.
    int32_t nValue1 = 0;
    int32_t nValue2 = 0;
    nNumChannels = 2;


    //calculate how many actual audio samples there are
    nNumSamples = nSampleRate * nNumChannels * nNumSeconds; 

    //allocate space to hold the audio data
    int32_t* pDataStereo = new int32_t[nNumSamples]; 

    for(int nIndex = 0; nIndex < nNumSamples; nIndex += 2){
        // The audio data itself is interleaved, 
        // meaning that the first audio sample is for the left channel, 
        // the second sample is for the right channel, 
        // the third sample is for the left channel, and so on.
        nValue1 += 8000000;
        nValue2 += 12000000;
        pDataStereo[nIndex] = nValue1; //left channel
        pDataStereo[nIndex+1] = nValue2; //right channel
    };

    WriteWaveFile("outstereo.wav",pDataStereo,nNumSamples * sizeof(pDataStereo[0]),nNumChannels,nSampleRate,sizeof(pDataStereo[0])*8);
    delete[] pDataStereo;


    /*-------- SINUSOIDAL WAVE --------------------*/
    // If we want to use a sine wave in our audio data, 
    // the first problem we hit is that sine has a value from -1 to 1, 
    // but our audio data from the last chapter is stored in a 32 bit int, 
    // which has a range of -2,147,483,648 to 2,147,483,647, and is unable to store fractional numbers.

    // The solution is to just map -1 to -2,147,483,648, 
    // and 1 to 2,147,483,647 and all the numbers in between represent fractional numbers between -1 and 1.  
    // 0.25 for instance would become 536,870,911.

    // If instead of 32 bits, we wanted to store the data in 16 bits, or 8 bits, we could do that as well.  
    // After generating our floating point audio data, we just convert it differently to get to those 16 bits and 8 bits.  
    // 16 bits have a range of -32,768 to 32,767 so 0.25 would convert to 8191.  In 8 bits, wave files want UNSIGNED 8 bit numbers, 
    // so the range is 0 to 255.   In that case,  0.25 would become 158.


    // how to generate a sine wave, respecting the sample rate and frequency we want to use:
    //make a naive sine wave
    
    nNumChannels = 1;
    nNumSamples = nSampleRate * nNumChannels * nNumSeconds; 
    int32_t* pDataSin = new int32_t[nNumSamples]; 

    int fFrequency = 44000;
    for(int nIndex = 0; nIndex < nNumSamples; ++nIndex){
        pDataSin[nIndex] = sin((float)nIndex * 2 * (float)M_PI * fFrequency / (float)nSampleRate);
    }

    WriteWaveFile("sinenaive.wav",pData,nNumSamples,nNumChannels,nSampleRate);
    delete[] pDataSin;


    return 0;
}

