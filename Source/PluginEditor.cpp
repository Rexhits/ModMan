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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ModManAudioProcessorEditor::ModManAudioProcessorEditor (ModManAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (cutoff = new Slider ("cutoff"));
    cutoff->setRange (20, 20000, 1);
    cutoff->setSliderStyle (Slider::Rotary);
    cutoff->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    cutoff->setColour (Slider::trackColourId, Colour (0xff95d6f2));
    cutoff->setColour (Slider::rotarySliderFillColourId, Colours::coral);
    cutoff->addListener (this);

    addAndMakeVisible (filterPicker = new ComboBox ("filterPicker"));
    filterPicker->setEditableText (false);
    filterPicker->setJustificationType (Justification::centredLeft);
    filterPicker->setTextWhenNothingSelected (TRANS("Filters..."));
    filterPicker->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filterPicker->addItem (TRANS("LP"), 1);
    filterPicker->addItem (TRANS("HP"), 2);
    filterPicker->addItem (TRANS("BP"), 3);
    filterPicker->addListener (this);

    addAndMakeVisible (resonance = new Slider ("resonance"));
    resonance->setRange (0, 0.9, 0.01);
    resonance->setSliderStyle (Slider::Rotary);
    resonance->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    resonance->setColour (Slider::trackColourId, Colour (0xff95d6f2));
    resonance->setColour (Slider::rotarySliderFillColourId, Colours::coral);
    resonance->addListener (this);

    addAndMakeVisible (cutoffLabel = new Label ("cutoffLabel",
                                                TRANS("Cutoff")));
    cutoffLabel->setFont (Font ("Bradley Hand", 25.00f, Font::plain).withExtraKerningFactor (0.100f));
    cutoffLabel->setJustificationType (Justification::centred);
    cutoffLabel->setEditable (false, false, false);
    cutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    cutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (resonanceLabel2 = new Label ("resonanceLabel",
                                                    TRANS("Resonance")));
    resonanceLabel2->setFont (Font ("Bradley Hand", 25.00f, Font::plain).withExtraKerningFactor (0.100f));
    resonanceLabel2->setJustificationType (Justification::centred);
    resonanceLabel2->setEditable (false, false, false);
    resonanceLabel2->setColour (TextEditor::textColourId, Colours::black);
    resonanceLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lfoSwitch = new ToggleButton ("lfoSwitch"));
    lfoSwitch->setButtonText (TRANS("LFO"));
    lfoSwitch->addListener (this);

    addAndMakeVisible (lfoFreq = new Slider ("lfoFreq"));
    lfoFreq->setRange (1, 40, 1);
    lfoFreq->setSliderStyle (Slider::Rotary);
    lfoFreq->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    lfoFreq->setColour (Slider::trackColourId, Colour (0xff95d6f2));
    lfoFreq->setColour (Slider::rotarySliderFillColourId, Colours::coral);
    lfoFreq->addListener (this);

    addAndMakeVisible (lfoFreqLabel = new Label ("lfoFreqLabel",
                                                 TRANS("Freq")));
    lfoFreqLabel->setFont (Font ("Bradley Hand", 25.00f, Font::plain).withExtraKerningFactor (0.100f));
    lfoFreqLabel->setJustificationType (Justification::centred);
    lfoFreqLabel->setEditable (false, false, false);
    lfoFreqLabel->setColour (TextEditor::textColourId, Colours::black);
    lfoFreqLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lfoDepth = new Slider ("lfoDepth"));
    lfoDepth->setRange (0, 1, 0.01);
    lfoDepth->setSliderStyle (Slider::Rotary);
    lfoDepth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    lfoDepth->setColour (Slider::trackColourId, Colour (0xff95d6f2));
    lfoDepth->setColour (Slider::rotarySliderFillColourId, Colours::coral);
    lfoDepth->addListener (this);

    addAndMakeVisible (lfoDepthLabel = new Label ("lfoDepthLabel",
                                                  TRANS("Depth")));
    lfoDepthLabel->setFont (Font ("Bradley Hand", 25.00f, Font::plain).withExtraKerningFactor (0.100f));
    lfoDepthLabel->setJustificationType (Justification::centred);
    lfoDepthLabel->setEditable (false, false, false);
    lfoDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    lfoDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    cutoff->setTextValueSuffix(" HZ");
    //[/UserPreSize]

    setSize (380, 600);


    //[Constructor] You can add your own custom stuff here..
    filterPickerAttachment = new ComboBoxAttachment(valueTreeState, "filterType", *filterPicker);
    cutoffAttachment = new SliderAttachment(valueTreeState, "cutoff", *cutoff);
    cutoff->setSkewFactorFromMidPoint(1000.0);
    cutoff->setRange (20, 20000, 1);
    resonanceAttachment = new SliderAttachment(valueTreeState, "resonance", *resonance);
    lfoSwitchAttachment = new ButtonAttachment(valueTreeState, "lfoSwitch", *lfoSwitch);
    lfoFreqAttachment = new SliderAttachment(valueTreeState, "lfoFreq", *lfoFreq);
    lfoFreq->setRange(1, 40, 1);
    lfoDepthAttachment = new SliderAttachment(valueTreeState, "lfoDepth", *lfoDepth);
    //[/Constructor]
}

ModManAudioProcessorEditor::~ModManAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    cutoff = nullptr;
    filterPicker = nullptr;
    resonance = nullptr;
    cutoffLabel = nullptr;
    resonanceLabel2 = nullptr;
    lfoSwitch = nullptr;
    lfoFreq = nullptr;
    lfoFreqLabel = nullptr;
    lfoDepth = nullptr;
    lfoDepthLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ModManAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ModManAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    cutoff->setBounds (50, 130, 120, 120);
    filterPicker->setBounds (78, 50, 232, 24);
    resonance->setBounds (210, 130, 120, 120);
    cutoffLabel->setBounds (50, 100, 120, 24);
    resonanceLabel2->setBounds (210, 100, 120, 24);
    lfoSwitch->setBounds (78, 281, 232, 35);
    lfoFreq->setBounds (50, 362, 120, 120);
    lfoFreqLabel->setBounds (50, 332, 120, 24);
    lfoDepth->setBounds (202, 362, 120, 120);
    lfoDepthLabel->setBounds (202, 332, 120, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ModManAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == cutoff)
    {
        //[UserSliderCode_cutoff] -- add your slider handling code here..
        //[/UserSliderCode_cutoff]
    }
    else if (sliderThatWasMoved == resonance)
    {
        //[UserSliderCode_resonance] -- add your slider handling code here..
        //[/UserSliderCode_resonance]
    }
    else if (sliderThatWasMoved == lfoFreq)
    {
        //[UserSliderCode_lfoFreq] -- add your slider handling code here..
        //[/UserSliderCode_lfoFreq]
    }
    else if (sliderThatWasMoved == lfoDepth)
    {
        //[UserSliderCode_lfoDepth] -- add your slider handling code here..
        //[/UserSliderCode_lfoDepth]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ModManAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == filterPicker)
    {
        //[UserComboBoxCode_filterPicker] -- add your combo box handling code here..
        //[/UserComboBoxCode_filterPicker]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ModManAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == lfoSwitch)
    {
        //[UserButtonCode_lfoSwitch] -- add your button handler code here..
        //[/UserButtonCode_lfoSwitch]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ModManAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="ModManAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p), valueTreeState (vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="380" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="cutoff" id="720f699055b2824c" memberName="cutoff" virtualName="Slider"
          explicitFocusOrder="0" pos="50 130 120 120" trackcol="ff95d6f2"
          rotarysliderfill="ffff7f50" min="20" max="20000" int="1" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <COMBOBOX name="filterPicker" id="129e9f2b320b5088" memberName="filterPicker"
            virtualName="" explicitFocusOrder="0" pos="78 50 232 24" editable="0"
            layout="33" items="LP&#10;HP&#10;BP" textWhenNonSelected="Filters..."
            textWhenNoItems="(no choices)"/>
  <SLIDER name="resonance" id="d9bc7fc260365670" memberName="resonance"
          virtualName="" explicitFocusOrder="0" pos="210 130 120 120" trackcol="ff95d6f2"
          rotarysliderfill="ffff7f50" min="0" max="0.9000000000000000222"
          int="0.010000000000000000208" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="cutoffLabel" id="42759f416d188808" memberName="cutoffLabel"
         virtualName="" explicitFocusOrder="0" pos="50 100 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bradley Hand" fontsize="25"
         kerning="0.10000000000000000555" bold="0" italic="0" justification="36"/>
  <LABEL name="resonanceLabel" id="6065066597d09ed3" memberName="resonanceLabel2"
         virtualName="" explicitFocusOrder="0" pos="210 100 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Resonance" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bradley Hand" fontsize="25"
         kerning="0.10000000000000000555" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="lfoSwitch" id="a93f1b63bcdf09db" memberName="lfoSwitch"
                virtualName="" explicitFocusOrder="0" pos="78 281 232 35" buttonText="LFO"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="lfoFreq" id="f4edbf8a98949f5" memberName="lfoFreq" virtualName=""
          explicitFocusOrder="0" pos="50 362 120 120" trackcol="ff95d6f2"
          rotarysliderfill="ffff7f50" min="1" max="40" int="1" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="lfoFreqLabel" id="b29a39095ece814b" memberName="lfoFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="50 332 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bradley Hand" fontsize="25"
         kerning="0.10000000000000000555" bold="0" italic="0" justification="36"/>
  <SLIDER name="lfoDepth" id="80c07bc25b545ae9" memberName="lfoDepth" virtualName=""
          explicitFocusOrder="0" pos="202 362 120 120" trackcol="ff95d6f2"
          rotarysliderfill="ffff7f50" min="0" max="1" int="0.010000000000000000208"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="lfoDepthLabel" id="9084ed902de77803" memberName="lfoDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="202 332 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Bradley Hand" fontsize="25"
         kerning="0.10000000000000000555" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
