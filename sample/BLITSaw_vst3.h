#pragma once
#include "public.sdk/source/vst/vstaudioeffect.h"

#include "bandlimited_sawtooth_oscillator_note_vst3.h"
#include "bandlimited_sawtooth_oscillator.h"
#include "resonance_filter.h"

#include <vector>

//{BDCB8A54-FFCB-4639-A045-9B7B3D3A36FF} (generated by http://www.guidgenerator.com)
#define PROCESSOR_UID1 0xBDCB8A54
#define PROCESSOR_UID2 0xFFCB4639
#define PROCESSOR_UID3 0xA0459B7B
#define PROCESSOR_UID4 0x3D3A36FF

//{5C69CE5D-8222-47E4-833F-DD97CFCD5876} (generated by http://www.guidgenerator.com)
#define CONTROLLER_UID1 0x5C69CE5D
#define CONTROLLER_UID2 0x822247E4
#define CONTROLLER_UID3 0x833FDD97
#define CONTROLLER_UID4 0xCFCD5876

namespace Steinberg { namespace Vst {
//-------------------------------------------------------------------------
// BLITSaw_vst3 Declaration
//-------------------------------------------------------------------------
class BLITSaw_vst3 : public AudioEffect
{
	/*コンストラクタ*/ 
	BLITSaw_vst3();
public:
	/*インスタンス生成*/
	static FUnknown* createInstance(void* context);

	/*初期化（オーバーライド）*/
	virtual tresult PLUGIN_API initialize(FUnknown* context);

	/*バス設定（オーバーライド）*/
	virtual tresult PLUGIN_API setBusArrangements(
		SpeakerArrangement* inputs,
		int32 numIns,
		SpeakerArrangement* outputs,
		int32 numOuts
	);

	/*音声処理（オーバーライド）*/
	virtual tresult PLUGIN_API process(ProcessData& data);

	virtual tresult PLUGIN_API setProcessing (TBool state);

protected:

	/// パラメータID.
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
