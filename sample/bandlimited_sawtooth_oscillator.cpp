#define _USE_MATH_DEFINES
#include <math.h>
#include "bandlimited_sawtooth_oscillator.h"
#include "bandlimited_sawtooth_oscillator_note.h"

//----------------
// �R���X�g���N�^
//----------------
bandlimited_sawtooth_oscillator::bandlimited_sawtooth_oscillator()
{
	// �T�C���g�e�[�u���쐬
	int ii = 0;
	for(; ii< _sinTable.size()-1; ii++)
	{
		_sinTable[ii] = sin( 2.0*M_PI * ii/(_sinTable.size()-1));
	}

	_sinTable[ii] = 0.0;
}

void bandlimited_sawtooth_oscillator::setFeedback(double value)
{
	_feedback = value;
}

//-------------
// 
//-------------
double bandlimited_sawtooth_oscillator::LinearInterpolatedSin( double x )
{
#ifdef _DEBUG
	if( x < 0.0 ) throw;
	if( 1.0 <= x ) throw;
#endif

	// �X�P�[�����O
	double pos = (_sinTable.size()-1) * x;

#ifdef _DEBUG
	if( pos >= _sinTable.size()-1 ) throw;
#endif

	// pos�����ނ悤�Ȑ���A,B���Z�o
	unsigned int idx_A = static_cast<int>(pos);

	// A����̋������Z�o
	double s = pos - idx_A;

	// ���`���
	return (1.0-s) * _sinTable[idx_A] + s*_sinTable[idx_A+1];
}

//-------------
// BLIT
//-------------
double bandlimited_sawtooth_oscillator::BLIT( double t, int N )
{
	if( t < 1.0e-12 )
	{
		// �[�����h�~�B���s�^���̒藝��K�p
		return (2.0 * N) * 2.0;
	}

	// ���q
	double x_numerator = LinearInterpolatedSin(::fmod((2.0*N+1.0)/2.0*t, 1.0));

	// ����
	double x_denominator = LinearInterpolatedSin( t/2.0 );

	return (x_numerator/x_denominator-1.0) * 2.0;
}

//-------------
//
//-------------
void bandlimited_sawtooth_oscillator::updateOcsillater(bandlimited_sawtooth_oscillator_note& note)
{
	note.t += note.dt;
	if ( 1.0 <= note.t )note.t -= 1.0;

	note.saw = note.saw*_feedback + BLIT(note.t, note.n)*note.dt;
}

void bandlimited_sawtooth_oscillator::updateEnvelope(bandlimited_sawtooth_oscillator_note &note)
{
	if( note.adsr == bandlimited_sawtooth_oscillator_note::Attack )
	{
		// Attack
		if( note.envelope + _attack_decrement < 1.0 )
		{
			note.envelope += _attack_decrement;
		}
		else
		{
			// Attack���萔
			note.envelope = 1.0;
			note.adsr = bandlimited_sawtooth_oscillator_note::Const;
		}
	}
	else if( note.adsr == bandlimited_sawtooth_oscillator_note::Release )
	{
		// Release
		if( 0.0 < note.envelope - _release_decrement )
		{
			note.envelope -= _release_decrement;
		}
		else
		{
			// �����[�X�I��
			note.envelope = 0.0;
			note.adsr = bandlimited_sawtooth_oscillator_note::Silent;

			// �j��
			note.kill();
		}
	}
}