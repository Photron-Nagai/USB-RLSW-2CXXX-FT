// CSample.h : CSAMPLE アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_CSAMPLE_H__4E822701_0A7C_463A_AA18_663D8DB028C4__INCLUDED_)
#define AFX_CSAMPLE_H__4E822701_0A7C_463A_AA18_663D8DB028C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CCSampleApp:
// このクラスの動作の定義に関しては CSample.cpp ファイルを参照してください。
//

class CCSampleApp : public CWinApp
{
public:
	CCSampleApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CCSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CCSampleApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CSAMPLE_H__4E822701_0A7C_463A_AA18_663D8DB028C4__INCLUDED_)
