// CSampleDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//
// Modified : Tue, Sep 21, 2021

#include "stdafx.h"
#include "CSample.h"
#include "CSampleDlg.h"

#include "sacom_usb_io_ft.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DevId 0
#define CHK_TIMER_ID 1

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// ���b�Z�[�W �n���h��������܂���B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSampleDlg �_�C�A���O

CCSampleDlg::CCSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCSampleDlg)
	m_CoilStatus0 = _T("");
	m_CoilStatus1 = _T("");
	m_CoilStatus2 = _T("");
	m_CoilStatus3 = _T("");
	m_CoilStatus4 = _T("");
	m_CoilStatus5 = _T("");
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCSampleDlg)
	DDX_Text(pDX, IDC_COIL_STATUS_0, m_CoilStatus0);
	DDX_Text(pDX, IDC_COIL_STATUS_1, m_CoilStatus1);
	DDX_Text(pDX, IDC_COIL_STATUS_2, m_CoilStatus2);
	DDX_Text(pDX, IDC_COIL_STATUS_3, m_CoilStatus3);
	DDX_Text(pDX, IDC_COIL_STATUS_4, m_CoilStatus4);
	DDX_Text(pDX, IDC_COIL_STATUS_5, m_CoilStatus5);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CCSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SET_BTN_0, OnSetBtn0)
	ON_BN_CLICKED(IDC_SET_BTN_1, OnSetBtn1)
	ON_BN_CLICKED(IDC_SET_BTN_2, OnSetBtn2)
	ON_BN_CLICKED(IDC_SET_BTN_3, OnSetBtn3)
	ON_BN_CLICKED(IDC_RESET_BTN_0, OnResetBtn0)
	ON_BN_CLICKED(IDC_RESET_BTN_1, OnResetBtn1)
	ON_BN_CLICKED(IDC_RESET_BTN_2, OnResetBtn2)
	ON_BN_CLICKED(IDC_RESET_BTN_3, OnResetBtn3)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_SET_BTN_4, OnSetBtn4)
	ON_BN_CLICKED(IDC_SET_BTN_5, OnSetBtn5)
	ON_BN_CLICKED(IDC_RESET_BTN_4, OnResetBtn4)
	ON_BN_CLICKED(IDC_RESET_BTN_5, OnResetBtn5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSampleDlg ���b�Z�[�W �n���h��

BOOL CCSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "�o�[�W�������..." ���j���[���ڂ��V�X�e�� ���j���[�֒ǉ����܂��B

	// IDM_ABOUTBOX �̓R�}���h ���j���[�͈̔͂łȂ���΂Ȃ�܂���B
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
	if( sacomUsbIoOpen(DevId) != TRUE )
	{
		AfxMessageBox("�f�o�C�X���I�[�v���ł��܂���");
		return FALSE;
	}
	SetTimer(CHK_TIMER_ID,300,NULL);

	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

void CCSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CCSampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CCSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCSampleDlg::OnTimer(UINT_PTR nIDEvent) 
{
	OnOffCheck();
	CDialog::OnTimer(nIDEvent);
}

void CCSampleDlg::OnOffCheck()
{
	unsigned long OnOff;

	if( sacomUsbIoReadback(DevId, &OnOff) != TRUE )
		return;
	else
    {

        if( OnOff & 0x0001 ) // Ch1 On �̎�
		    m_CoilStatus0 = "ON";
	    else
		    m_CoilStatus0 = "OFF";
        if( OnOff & 0x0002 ) // Ch2 On �̎�
		    m_CoilStatus1 = "ON";
	    else
		    m_CoilStatus1 = "OFF";
        if( OnOff & 0x0004 ) // Ch3 On �̎�
		    m_CoilStatus2 = "ON";
	    else
		    m_CoilStatus2 = "OFF";
        if( OnOff & 0x0008 ) // Ch4 On �̎�
		    m_CoilStatus3 = "ON";
	    else
		    m_CoilStatus3 = "OFF";
        if( OnOff & 0x0010 ) // Ch5 On �̎�
		    m_CoilStatus4 = "ON";
	    else
		    m_CoilStatus4 = "OFF";
        if( OnOff & 0x0020 ) // Ch6 On �̎�
		    m_CoilStatus5 = "ON";
	    else
		    m_CoilStatus5 = "OFF";
    }
	UpdateData(FALSE);
}

void CCSampleDlg::SetBtn(char ch)
{
	if( sacomUsbIoBit(DevId, ch, TRUE) != TRUE )
	{
		AfxMessageBox("���s���܂���");
		return;
	}
}

void CCSampleDlg::OnSetBtn0() 
{
	SetBtn(0);
}

void CCSampleDlg::OnSetBtn1() 
{
	SetBtn(1);
}

void CCSampleDlg::OnSetBtn2() 
{
	SetBtn(2);
}

void CCSampleDlg::OnSetBtn3() 
{
	SetBtn(3);
}

void CCSampleDlg::OnSetBtn4() 
{
	SetBtn(4);
}

void CCSampleDlg::OnSetBtn5() 
{
	SetBtn(5);
}

void CCSampleDlg::ResetBtn(char ch)
{
	if( sacomUsbIoBit(DevId, ch, FALSE) != TRUE )
	{
		AfxMessageBox("���s���܂���");
		return;
	}
}


void CCSampleDlg::OnResetBtn0() 
{
	ResetBtn(0);
}

void CCSampleDlg::OnResetBtn1() 
{
	ResetBtn(1);
}

void CCSampleDlg::OnResetBtn2() 
{
	ResetBtn(2);
}

void CCSampleDlg::OnResetBtn3() 
{
	ResetBtn(3);
}

void CCSampleDlg::OnResetBtn4() 
{
	ResetBtn(4);
}

void CCSampleDlg::OnResetBtn5() 
{
	ResetBtn(5);
}

void CCSampleDlg::OnClose() 
{
	sacomUsbIoClose(DevId);
	CDialog::OnClose();
}


