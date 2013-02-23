#include "BLITSaw_vst3.h"
#include "BLITSaw_vst3_controller.h"
#include "BLITSaw_vst3_guids.h"
#include "public.sdk/source/main//pluginfactoryvst3.h"

//------------------------------------------------------------------------
// DLL���[�h��ɌĂ΂��
//------------------------------------------------------------------------
bool InitModule()
{
	/*�������Ȃ�*/
	return true;
}

//------------------------------------------------------------------------
// DLL�A�����[�h��ɌĂ΂��
//------------------------------------------------------------------------
bool DeinitModule()
{
	/*�������Ȃ�*/
	return true;
}

using namespace Steinberg::Vst;

//------------------------------------------------------------------------
// �t�@�N�g����`
//------------------------------------------------------------------------
BEGIN_FACTORY_DEF(
	"fukuroda",							// �쐬��
	"https://github.com/fukuroder",		// �z���y
	"mailto:fukuroder@live.jp"			// ���A�h
)

/*�v���Z�b�T�[�̓o�^*/
DEF_CLASS2(
	INLINE_UID_FROM_FUID(AGainProcessorUID),/*�i���ߑł��j*/
	PClassInfo::kManyInstances,	/*�i���ߑł��j*/
	kVstAudioEffectClass,		/*�v���Z�b�T�[�ł���*/
	"BLITSawOscillatorVST3",					/*�v���O�C����*/
	kDistributable,		/*�v���Z�b�T�[�ƃR���g���[���[��������Ă܂���*/
	PlugType::kInstrumentSynth,	/*�T�u�J�e�S���[*/
	"1.0.0.000",				/*�v���O�C���o�[�W����*/
	kVstVersionString,			/*�i���ߑł��j*/
	BLITSaw_vst3::createInstance		/*BLITSaw_vst3�C���X�^���X�������\�b�h*/
)

/*�R���g���[���[�̓o�^*/
DEF_CLASS2(
	INLINE_UID_FROM_FUID(AGainControllerUID),/*�i���ߑł��j*/
	PClassInfo::kManyInstances,		/*�i���ߑł��j*/
	kVstComponentControllerClass,	/*�R���g���[���[�ł���*/
	"BLITSawOscillatorVST3 Controller",			/*�v���O�C����*/
	0,								/*�i���g�p�j*/
	"",								/*�i���g�p�j*/
	"1.0.0.000",					/*�v���O�C���o�[�W����*/
	kVstVersionString,				/*�i���ߑł��j*/
	BLITSaw_vst3_controller::create	/*BLITSaw_vst3_controller�C���X�^���X�������\�b�h*/
)
END_FACTORY
