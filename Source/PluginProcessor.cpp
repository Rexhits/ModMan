/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================

static String invertFreqToText(float value)
{
    return String(roundToInt(value));
}


ModManAudioProcessor::ModManAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this, nullptr)
#endif
{
    parameters.createAndAddParameter("filterType", "filterType", String(), NormalisableRange<float> (0.0f, 2.0f), 0.0f, nullptr, nullptr);
    parameters.createAndAddParameter("cutoff", "Cutoff", String(), NormalisableRange<float> (20.0f, 20000.0f), 500.0f, invertFreqToText, nullptr);
    parameters.createAndAddParameter("resonance", "Resonance", String(), NormalisableRange<float> (0.0f, 1.0f), 0.1f, nullptr, nullptr);
    parameters.createAndAddParameter("lfoSwitch", "LfoSwitch", String(), NormalisableRange<float> (0.0f, 1.0f), 0.0f, nullptr, nullptr);
    parameters.createAndAddParameter("lfoFreq", "LfoFreq", String(), NormalisableRange<float> (0.0f, 40.0f), 5.0f, nullptr, nullptr);
    parameters.createAndAddParameter("lfoDepth", "LfoDepth", String(), NormalisableRange<float> (0.0f, 1.0f), 1.0f, nullptr, nullptr);
}

ModManAudioProcessor::~ModManAudioProcessor()
{
}

//==============================================================================



const String ModManAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ModManAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ModManAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ModManAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ModManAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ModManAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ModManAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ModManAudioProcessor::setCurrentProgram (int index)
{
}

const String ModManAudioProcessor::getProgramName (int index)
{
    return {};
}

void ModManAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================

void ModManAudioProcessor::updateParameters() {
    filterType = *parameters.getRawParameterValue("filterType");
    cutoff = *parameters.getRawParameterValue("cutoff");
    resonance = *parameters.getRawParameterValue("resonance");
    lfoSwitch = *parameters.getRawParameterValue("lfoSwitch");
    lfoFreq = *parameters.getRawParameterValue("lfoFreq");
    lfoDepth = *parameters.getRawParameterValue("lfoDepth");
}

void ModManAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    sinOSC.reset();
    updateParameters();
}



void ModManAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ModManAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ModManAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();
    updateParameters();
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool ModManAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ModManAudioProcessor::createEditor()
{
    return new ModManAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void ModManAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    ScopedPointer<XmlElement> xml (parameters.state.createXml());
    if (xml != nullptr)
        if (xml->hasTagName(parameters.state.getType()))
            copyXmlToBinary(*xml, destData);
}

void ModManAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary(data, sizeInBytes));
    
    if (xmlState != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.state = ValueTree::fromXml(*xmlState);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ModManAudioProcessor();
}
