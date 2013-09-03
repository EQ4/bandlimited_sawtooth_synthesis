﻿#pragma once
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "BLITSaw_oscillator.h"
#include <array>

namespace Steinberg { namespace Vst {

//
class BLITSaw_processor : public AudioEffect
{
	// constructor(private)
	BLITSaw_processor();

public:
	// create
	static FUnknown* create(void* context);

	// from AudioEffect class
	virtual tresult PLUGIN_API initialize(FUnknown* context);
	virtual tresult PLUGIN_API setBusArrangements(
		SpeakerArrangement* inputs,
		int32 numIns,
		SpeakerArrangement* outputs,
		int32 numOuts
		);
	virtual tresult PLUGIN_API setProcessing (TBool state);
	virtual tresult PLUGIN_API process(ProcessData& data);

protected:

	// パラメータID.
	enum
	{
		Leak,
	};

	//
	std::array<bandlimited_sawtooth_oscillator_note, 8> _notes;

	//
	bandlimited_sawtooth_oscillator blit;
};

}} // namespace
