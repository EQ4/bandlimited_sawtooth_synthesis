#pragma once

// include
#include "bandlimited_sawtooth_oscillator_note.h"
#include "pluginterfaces/vst/ivstevents.h"

namespace Steinberg {namespace Vst {

/// FLStudio�pBLIT�m�R�M���g�m�[�g�N���X.
class bandlimited_sawtooth_oscillator_note_vst3 : public bandlimited_sawtooth_oscillator_note
{
public:

	/// �R���X�g���N�^.
	bandlimited_sawtooth_oscillator_note_vst3(int sampleRate);

	virtual ~bandlimited_sawtooth_oscillator_note_vst3();

	/// �m�[�g�I��.
	void trigger(const NoteOnEvent& noteOn);

	/// �^�O�擾.
	int32 id()const;

	/// ���g���X�V
	void updateFrequency();

	void setFinePitch(double finePitch);

	void setCorasePitch(double CorasePitch);

	void setPitchBend(double pitchBend);

	/// �m�[�g�j��.
	virtual void kill();

	/// �x���V�e�B�擾.
	virtual double velocity();

protected:

	NoteOnEvent _noteOn;

	int _sampleRate;

	/// ���g��.
	double _old_pitch_bend;
	double _pitch_bend;

	double _old_param_osci_coarse;
	double _param_osci_coarse;

	double _old_param_osci_fine;
	double _param_osci_fine;

	/// �����̃m�[�g�i���o�[
	static const int _note_no_center = 69;
};

}}