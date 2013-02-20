#pragma once

/// BLIT�m�R�M���g�m�[�g���N���X.
class bandlimited_sawtooth_oscillator_note
{
public:

	/// ADSR.
	enum ADSR
	{
		Silent,	///< ����
		Attack,	///< �A�^�b�N
		Const,	///< ���
		Release ///< �����[�X
	};

	/// �R���X�g���N�^.
	bandlimited_sawtooth_oscillator_note();

	//void updateEnvelope();

	/// �m�[�g�I��.
	void trigger(double pitch, int srate);

	/// ���g���X�V.
	void updateFrequency(double pitch, int srate);

	void setFinePitch(double finePitch);

	void setCorasePitch(double CorasePitch);

	/// �m�[�g�����[�X.
	void release();

	/// �m�[�g�j��.
	virtual void kill() = 0;

	/// �x���V�e�B�擾.
	virtual double velocity() = 0;

	/// ADSR.
	ADSR	adsr;

	/// �G���x���[�v.
	double	envelope;

	/// ���݂̎���.
	double	t;

	/// ���݂̒l.
	double	saw;
	
	/// �{����.
	int		n;

	/// ���ݕ�.
	double	dt;
};
