
// MFCTestDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCTest.h"
#include "MFCTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTestDlg ダイアログ



CMFCTestDlg::CMFCTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCTestDlg メッセージ ハンドラー

BOOL CMFCTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMFCTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFCTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// ダブルクリック
void CMFCTestDlg::OnBnClickedButton1()
{
	// ファイルパス -----------
	CString fullPathName = _T("D:\\test.csv");
	// ------------------------


	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CStdioFile csvFile;
    CFileException e;
    CString csvLine;

	// 追加↓ -----------------------------------------------
	CString allData;
	// 追加↑ -----------------------------------------------

    // CSVファイルを読み取り専用で開く
    if (csvFile.Open(fullPathName, CFile::modeRead | CFile::typeText, &e))
    {

        // カラムのインデックス
        int iCsvData = 0;

        // 行のインデックス
        int iCsvLine = 0;

        // データ
        CString csvData;

        // 1行読み取り中フラグ
        BOOL isCsvLineRead = FALSE;

        // 1行読み取り
        while(csvFile.ReadString(csvLine))
        {
            // csvLineに1行分の文字列が格納されている

            if (isCsvLineRead)
            {
                // データの中に改行が有り、改行コードの代わりに印を付ける
                // 場合は、ここで付ける。例えば、「[改行]」という文字列を
                // 入れる場合、次のコメント解除
                //csvData += L"[改行]";
            }
            else
            {
                iCsvData = 0;
                isCsvLineRead = TRUE;
            }

            // カンマ検索開始位置のインデックス
            int iStart = 0;

            while(isCsvLineRead)
            {
                // カンマのインデックス
                int iFind = csvLine.Find(L',', iStart);

                if (iFind == -1)
                {
                    // データ読み取り
                    // (行の最後)
                    csvData += csvLine.Mid(iStart);

                    // 行末の空白を削除する場合、次のコメント解除
                    //csvData.TrimRight();

                    isCsvLineRead = FALSE;
                }
                else
                {
                    // データ読み取り
                    // (行の最後以外)
                    csvData += csvLine.Mid(iStart, iFind - iStart);
                }

                // データがダブルクォートで囲まれている場合
                if (csvData.GetAt(0) == L'"')
                {
                    // ダブルクォートの直後に改行がある場合の対策として、
                    // csvData.GetLength()>1の判定を追加
                    if (csvData.GetLength() > 1 && csvData.GetAt(csvData.GetLength() - 1) == L'"')
                    {
                        // ダブルクォートの削除
                        csvData.Delete(csvData.GetLength() - 1);
                        csvData.Delete(0);
                    }
                    else
                    {
                        iStart = iFind + 1;

                        if (isCsvLineRead)
                        {
                            // ダブルクォートで囲まれた中にカンマがある
                            csvData += L',';
                            continue;
                        }
                        else
                        {
                            // ダブルクォートで囲まれた中に改行がある
                            isCsvLineRead = TRUE;
                            break;
                        }
                    }
                }

                // データの中に、ダブルクォートが2個連続する場合、1個を削除
                int iWQuote = -1;

                do
                {
                    iWQuote = csvData.Find(L"\"\"");

                    if (iWQuote != -1)
                    {
                        csvData.Delete(iWQuote);
                    }
                }
                while (iWQuote != -1);

                // ここで、
                // iCsvLine に、行のインデックス(ゼロ開始)
                // iCsvData に、カラムのインデックス(ゼロ開始)
                // csvData に、データが格納されている
                //

                // カンマ検索開始位置の更新
                iStart = iFind + 1;

                // データのメモリ解放
                csvData.Empty();

                // カラムのインデックスをインクリメント
                iCsvData++;

				// 追加↓ -----------------------------------------------
				allData += csvLine;
				allData += "\n";
				// 追加↑ -----------------------------------------------
            }

            if (!isCsvLineRead)
            {
                // 行のインデックスをインクリメント
                iCsvLine++;
            }
        }
    }
    else
    {
        // ファイルを開くのを失敗
        return;
    }

    // ファイルを閉じる
    csvFile.Close();

	// メッセージボックス
	MessageBox(allData, _T("データ"));

    return;
}
