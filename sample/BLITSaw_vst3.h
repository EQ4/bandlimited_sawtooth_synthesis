#pragma once
#include "public.sdk/source/vst/vstaudioeffect.h"

#include "bandlimited_sawtooth_oscillator_note_vst3.h"
#include "bandlimited_sawtooth_oscillator.h"
#include "resonance_filter.h"

#include <vector>

namespace Steinberg { namespace Vst {

//-------------------------------------------------------------------------
// BLITSaw_vst3 Declaration
//-------------------------------------------------------------------------
class BLITSaw_vst3 : public AudioEffect
{
	/*�R���X�g���N�^*/ 
	BLITSaw_vst3();

public:
	/*�C���X�^���X����*/
	static FUnknown* createInstance(void* context);

	/*�������i�I�[�o�[���C�h�j*/
	virtual tresult PLUGIN_API initialize(FUnknown* context);

	/*�o�X�ݒ�i�I�[�o�[���C�h�j*/
	virtual tresult PLUGIN_API setBusArrangements(
		SpeakerArrangement* inputs,
		int32 numIns,
		SpeakerArrangement* outputs,
		int32 numOuts
	);

	/*���������i�I�[�o�[���C�h�j*/
	virtual tresult PLUGIN_API process(ProcessData& data);

	virtual tresult PLUGIN_API setProcessing (TBool state);

protected:

	/// �p�����[�^ID.
	enum
	{
		feedback,
		coarse,		///<
		fine,		///<
		attack,		///<
		release,	///<
		cutoff,
		resonance,
		high,
		band,
		low,
	};

	std::vector<bandlimited_sawtooth_oscillator_note_vst3> _notes;

	bandlimited_sawtooth_oscillator blit;

	resonance_filter _filter;
};
}}
