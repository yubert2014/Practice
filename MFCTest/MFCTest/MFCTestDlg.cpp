
// MFCTestDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MFCTest.h"
#include "MFCTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
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


// CMFCTestDlg �_�C�A���O



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


// CMFCTestDlg ���b�Z�[�W �n���h���[

BOOL CMFCTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "�o�[�W�������..." ���j���[���V�X�e�� ���j���[�ɒǉ����܂��B

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
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

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
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

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CMFCTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CMFCTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// �_�u���N���b�N
void CMFCTestDlg::OnBnClickedButton1()
{
	// �t�@�C���p�X -----------
	CString fullPathName = _T("D:\\test.csv");
	// ------------------------


	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CStdioFile csvFile;
    CFileException e;
    CString csvLine;

	// �ǉ��� -----------------------------------------------
	CString allData;
	// �ǉ��� -----------------------------------------------

    // CSV�t�@�C����ǂݎ���p�ŊJ��
    if (csvFile.Open(fullPathName, CFile::modeRead | CFile::typeText, &e))
    {

        // �J�����̃C���f�b�N�X
        int iCsvData = 0;

        // �s�̃C���f�b�N�X
        int iCsvLine = 0;

        // �f�[�^
        CString csvData;

        // 1�s�ǂݎ�蒆�t���O
        BOOL isCsvLineRead = FALSE;

        // 1�s�ǂݎ��
        while(csvFile.ReadString(csvLine))
        {
            // csvLine��1�s���̕����񂪊i�[����Ă���

            if (isCsvLineRead)
            {
                // �f�[�^�̒��ɉ��s���L��A���s�R�[�h�̑���Ɉ��t����
                // �ꍇ�́A�����ŕt����B�Ⴆ�΁A�u[���s]�v�Ƃ����������
                // �����ꍇ�A���̃R�����g����
                //csvData += L"[���s]";
            }
            else
            {
                iCsvData = 0;
                isCsvLineRead = TRUE;
            }

            // �J���}�����J�n�ʒu�̃C���f�b�N�X
            int iStart = 0;

            while(isCsvLineRead)
            {
                // �J���}�̃C���f�b�N�X
                int iFind = csvLine.Find(L',', iStart);

                if (iFind == -1)
                {
                    // �f�[�^�ǂݎ��
                    // (�s�̍Ō�)
                    csvData += csvLine.Mid(iStart);

                    // �s���̋󔒂��폜����ꍇ�A���̃R�����g����
                    //csvData.TrimRight();

                    isCsvLineRead = FALSE;
                }
                else
                {
                    // �f�[�^�ǂݎ��
                    // (�s�̍Ō�ȊO)
                    csvData += csvLine.Mid(iStart, iFind - iStart);
                }

                // �f�[�^���_�u���N�H�[�g�ň͂܂�Ă���ꍇ
                if (csvData.GetAt(0) == L'"')
                {
                    // �_�u���N�H�[�g�̒���ɉ��s������ꍇ�̑΍�Ƃ��āA
                    // csvData.GetLength()>1�̔����ǉ�
                    if (csvData.GetLength() > 1 && csvData.GetAt(csvData.GetLength() - 1) == L'"')
                    {
                        // �_�u���N�H�[�g�̍폜
                        csvData.Delete(csvData.GetLength() - 1);
                        csvData.Delete(0);
                    }
                    else
                    {
                        iStart = iFind + 1;

                        if (isCsvLineRead)
                        {
                            // �_�u���N�H�[�g�ň͂܂ꂽ���ɃJ���}������
                            csvData += L',';
                            continue;
                        }
                        else
                        {
                            // �_�u���N�H�[�g�ň͂܂ꂽ���ɉ��s������
                            isCsvLineRead = TRUE;
                            break;
                        }
                    }
                }

                // �f�[�^�̒��ɁA�_�u���N�H�[�g��2�A������ꍇ�A1���폜
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

                // �����ŁA
                // iCsvLine �ɁA�s�̃C���f�b�N�X(�[���J�n)
                // iCsvData �ɁA�J�����̃C���f�b�N�X(�[���J�n)
                // csvData �ɁA�f�[�^���i�[����Ă���
                //

                // �J���}�����J�n�ʒu�̍X�V
                iStart = iFind + 1;

                // �f�[�^�̃��������
                csvData.Empty();

                // �J�����̃C���f�b�N�X���C���N�������g
                iCsvData++;

				// �ǉ��� -----------------------------------------------
				allData += csvLine;
				allData += "\n";
				// �ǉ��� -----------------------------------------------
            }

            if (!isCsvLineRead)
            {
                // �s�̃C���f�b�N�X���C���N�������g
                iCsvLine++;
            }
        }
    }
    else
    {
        // �t�@�C�����J���̂����s
        return;
    }

    // �t�@�C�������
    csvFile.Close();

	// ���b�Z�[�W�{�b�N�X
	MessageBox(allData, _T("�f�[�^"));

    return;
}
