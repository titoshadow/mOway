
// mOwayDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CmOwayDlg
class CmOwayDlg : public CDialogEx
{
// Construcción
public:
	CmOwayDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOWAY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl sliderLeft;
	CSliderCtrl sliderRight;
	CProgressCtrl pBLight;
	CStatic labelLight;
	CProgressCtrl pBBattery;
	CStatic labelBattery;
	CButton radioLED1;
	CButton radioLED2;
	CButton radioLED3;
	CButton radioLED4;
	CWinThread* m_ThreadUpdate;
	CButton checkThread;
	bool connected = false;
	void OnDestroy();
	void FlushAndDisconnect(bool dc);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg void OnBnClickedButtonUp();
	afx_msg void OnBnClickedButtonDown();
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonLed1();
	afx_msg void OnBnClickedButtonLed2();
	afx_msg void OnBnClickedButtonLed3();
	afx_msg void OnBnClickedButtonLed4();
	afx_msg void OnBnClickedRadioLed1();
	afx_msg void OnBnClickedRadioLed2();
	afx_msg void OnBnClickedRadioLed3();
	afx_msg void OnBnClickedRadioLed4();
	afx_msg void OnNMReleasedcaptureSliderLeft(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMReleasedcaptureSliderRight(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonLedOff();
	afx_msg void OnBnClickedButtonReloadLight();
	afx_msg void OnBnClickedCheckThread();
	afx_msg void OnBnClickedButtonReloadBattery();
	static UINT MyThread(LPVOID pParam);
	void ChangeMotorSpeed(int lefSlider = NULL, int rightSlider = NULL);
	CProgressCtrl pBPLeft;
	CProgressCtrl pBPCLeft;
	CProgressCtrl pBPCRight;
	CProgressCtrl pBPRight;
	CStatic staticKM;
	afx_msg void OnBnClickedButtonReloadProximity();
	CProgressCtrl pBTemp;
	CProgressCtrl pBNoise;
	CProgressCtrl pBX;
	CProgressCtrl pBY;
	CProgressCtrl pBZ;
	afx_msg void OnBnClickedButtonReloadMisc();
	CButton buttonReloadLight;
	CButton buttonReloadBattery;
	CButton buttonReloadProximity;
	CButton buttonReloadMisc;
};
