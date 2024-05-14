// CSampleDlg.h : ヘッダー ファイル
//

#if !defined(AFX_CSAMPLEDLG_H__2601164F_49B9_4620_B997_C9005ED34BEC__INCLUDED_)
#define AFX_CSAMPLEDLG_H__2601164F_49B9_4620_B997_C9005ED34BEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSampleDlg ダイアログ

class CCSampleDlg : public CDialog
{
// 構築
public:
	CCSampleDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CCSampleDlg)
	enum { IDD = IDD_CSAMPLE_DIALOG };
	CString	m_CoilStatus0;
	CString	m_CoilStatus1;
	CString	m_CoilStatus2;
	CString	m_CoilStatus3;
	CString	m_CoilStatus4;
	CString	m_CoilStatus5;
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CCSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CCSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSetBtn0();
	afx_msg void OnSetBtn1();
	afx_msg void OnSetBtn2();
	afx_msg void OnSetBtn3();
	afx_msg void OnResetBtn0();
	afx_msg void OnResetBtn1();
	afx_msg void OnResetBtn2();
	afx_msg void OnResetBtn3();
	afx_msg void OnClose();
	afx_msg void OnSetBtn4();
	afx_msg void OnSetBtn5();
	afx_msg void OnResetBtn4();
	afx_msg void OnResetBtn5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ResetBtn(char ch);
	void SetBtn(char ch);
	void OnOffCheck();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CSAMPLEDLG_H__2601164F_49B9_4620_B997_C9005ED34BEC__INCLUDED_)
