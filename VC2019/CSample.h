// CSample.h : CSAMPLE �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_CSAMPLE_H__4E822701_0A7C_463A_AA18_663D8DB028C4__INCLUDED_)
#define AFX_CSAMPLE_H__4E822701_0A7C_463A_AA18_663D8DB028C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CCSampleApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� CSample.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CCSampleApp : public CWinApp
{
public:
	CCSampleApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CCSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CCSampleApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CSAMPLE_H__4E822701_0A7C_463A_AA18_663D8DB028C4__INCLUDED_)
