/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
 An auto-generated component, created by the Projucer.

 Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ModManAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Slider::Listener,
                                    public ComboBox::Listener,
                                    public Button::Listener
{
public:
    //==============================================================================
    ModManAudioProcessorEditor (ModManAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~ModManAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ModManAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
    typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    ScopedPointer<SliderAttachment> cutoffAttachment;
    ScopedPointer<SliderAttachment> resonanceAttachment;
    ScopedPointer<SliderAttachment> lfoFreqAttachment;
    ScopedPointer<SliderAttachment> lfoDepthAttachment;
    ScopedPointer<ButtonAttachment> lfoSwitchAttachment;
    ScopedPointer<ComboBoxAttachment> filterPickerAttachment;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> cutoff;
    ScopedPointer<ComboBox> filterPicker;
    ScopedPointer<Slider> resonance;
    ScopedPointer<Label> cutoffLabel;
    ScopedPointer<Label> resonanceLabel2;
    ScopedPointer<ToggleButton> lfoSwitch;
    ScopedPointer<Slider> lfoFreq;
    ScopedPointer<Label> lfoFreqLabel;
    ScopedPointer<Slider> lfoDepth;
    ScopedPointer<Label> lfoDepthLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModManAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
