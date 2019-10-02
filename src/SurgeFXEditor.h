/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SurgeFXProcessor.h"
#include "SurgeLookAndFeel.h"
#include <functional>
#include <list>

//==============================================================================
/**
*/
class SurgefxAudioProcessorEditor  : public AudioProcessorEditor, AsyncUpdater
{
public:
    SurgefxAudioProcessorEditor (SurgefxAudioProcessor&);
    ~SurgefxAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void paramsChangedCallback();
    void setEffectType(int i);

    virtual void handleAsyncUpdate() override;
    
    enum RadioGroupIds {
        FxTypeGroup = 1776
    };
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SurgefxAudioProcessor& processor;

    Slider fxParamSliders[n_fx_params];
    SurgeFXParamDisplay fxParamDisplay[n_fx_params];
    SurgeTempoSyncSwitch fxTempoSync[n_fx_params];
    
    TextButton selectType[10]; // this had better match the list of fxnames in the constructor
    Slider fxTypeSlider;

    void blastToggleState(int i);
    void resetLabels();
    
    std::unique_ptr<SurgeLookAndFeel> surgeLookFeel;

    ///
    void addButtonClickCallback(Button &b, std::function<void()> f);
    void addSliderValueCallback(Slider &s, std::function<void()> f);
    void addSliderDragStartCallback(Slider &s, std::function<void()> f);
    void addSliderDragEndCallback(Slider &s, std::function<void()> f);

    std::list<std::unique_ptr<Button::Listener>> buttonListeners;
    std::list<std::unique_ptr<Slider::Listener>> sliderListeners;
    ///

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SurgefxAudioProcessorEditor)
};
