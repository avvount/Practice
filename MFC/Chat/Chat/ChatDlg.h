
// ChatDlg.h : 头文件
//

#pragma once
#define WM_RECVDATA WM_USER+1

// CChatDlg 对话框
class CChatDlg : public CDialog
{
// 构造
public:
	CChatDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg LRESULT OnRecvData(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
    SOCKET m_socket;
    bool InitSocket(void);
    static DWORD WINAPI RecvProc(LPVOID lpParameter);
public:
    afx_msg void OnBnClickedBtnSend();
    afx_msg void OnBnClickedCmd();
};

struct RECVPARAM
{
    SOCKET sock;
    HWND hwnd;
};