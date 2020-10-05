
// mOwayDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "mOway.h"
#include "mOwayDlg.h"
#include "afxdialogex.h"
#include "CMoway.h"

CMoway miMoway;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CmOwayDlg



CmOwayDlg::CmOwayDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MOWAY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmOwayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmOwayDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CmOwayDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CmOwayDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CmOwayDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CmOwayDlg::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CmOwayDlg::OnBnClickedButtonDown)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CmOwayDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CmOwayDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CmOwayDlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_LED1, &CmOwayDlg::OnBnClickedButtonLed1)
	ON_BN_CLICKED(IDC_BUTTON_LED2, &CmOwayDlg::OnBnClickedButtonLed2)
	ON_BN_CLICKED(IDC_BUTTON_LED3, &CmOwayDlg::OnBnClickedButtonLed3)
	ON_BN_CLICKED(IDC_BUTTON_LED4, &CmOwayDlg::OnBnClickedButtonLed4)
	ON_BN_CLICKED(IDC_RADIO_LED1, &CmOwayDlg::OnBnClickedRadioLed1)
	ON_BN_CLICKED(IDC_RADIO_LED2, &CmOwayDlg::OnBnClickedRadioLed2)
	ON_BN_CLICKED(IDC_RADIO_LED3, &CmOwayDlg::OnBnClickedRadioLed3)
	ON_BN_CLICKED(IDC_RADIO_LED4, &CmOwayDlg::OnBnClickedRadioLed4)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RIGHT, &CmOwayDlg::OnNMCustomdrawSliderRight)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_LEFT, &CmOwayDlg::OnNMCustomdrawSliderLeft)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_LEFT, &CmOwayDlg::OnNMReleasedcaptureSliderLeft)
END_MESSAGE_MAP()


// Controladores de mensajes de CmOwayDlg

BOOL CmOwayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional


	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CmOwayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
	if (nID == SC_CLOSE)
	{
		miMoway.DisconnectMoway();
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CmOwayDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CmOwayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void PowerOffAllLEDs()
{
	miMoway.ChangeLEDState(CMoway::leds::LED_BRAKE, CMoway::led_action::OFF);
	miMoway.ChangeLEDState(CMoway::leds::LED_FRONT, CMoway::led_action::OFF);
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_GREEN, CMoway::led_action::OFF);
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_RED, CMoway::led_action::OFF);
}


void CmOwayDlg::OnBnClickedOk()
{
	FlushAndDisconnect();
	CDialogEx::OnOK();
}


void CmOwayDlg::OnBnClickedButtonConnect()
{
	miMoway.ConnectMoway(22);
}


void CmOwayDlg::OnBnClickedButtonDisconnect()
{
	FlushAndDisconnect();
}


void CmOwayDlg::OnDestroy()
{
	FlushAndDisconnect();
}


void CmOwayDlg::FlushAndDisconnect()
{
	miMoway.SetSpeed(0, 0, CMoway::FORWARD, CMoway::FORWARD, 0, 0);
	PowerOffAllLEDs();
	miMoway.DisconnectMoway();
}


void CmOwayDlg::OnBnClickedButtonUp()
{
	miMoway.GoStraight(1, CMoway::FORWARD, 0);
}


void CmOwayDlg::OnBnClickedButtonDown()
{
	miMoway.GoStraight(50, CMoway::BACKWARD, 0);
}


void CmOwayDlg::OnBnClickedButtonRight()
{
	miMoway.SetSpeed(25, 25, CMoway::FORWARD, CMoway::BACKWARD, 5, 5);
}


void CmOwayDlg::OnBnClickedButtonLeft()
{
	miMoway.SetSpeed(25, 25, CMoway::BACKWARD, CMoway::FORWARD, 5, 5);
}


void CmOwayDlg::OnBnClickedButtonStop()
{
	miMoway.SetSpeed(0, 0, CMoway::FORWARD, CMoway::FORWARD, 1, 1);
}


void CmOwayDlg::OnBnClickedButtonLed1()
{
	miMoway.ChangeLEDState(CMoway::leds::LED_BRAKE, CMoway::led_action::ON);
	Sleep(3000);
	miMoway.ChangeLEDState(CMoway::leds::LED_BRAKE, CMoway::led_action::OFF);
}



void CmOwayDlg::OnBnClickedButtonLed2()
{
	miMoway.ChangeLEDState(CMoway::leds::LED_FRONT, CMoway::led_action::ON);
	Sleep(3000);
	miMoway.ChangeLEDState(CMoway::leds::LED_FRONT, CMoway::led_action::OFF);
}


void CmOwayDlg::OnBnClickedButtonLed3()
{
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_GREEN, CMoway::led_action::ON);
	Sleep(3000);
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_GREEN, CMoway::led_action::OFF);
}


void CmOwayDlg::OnBnClickedButtonLed4()
{
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_RED, CMoway::led_action::ON);
	Sleep(3000);
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_RED, CMoway::led_action::OFF);
}


void CmOwayDlg::OnBnClickedRadioLed1()
{
	PowerOffAllLEDs();
	miMoway.ChangeLEDState(CMoway::leds::LED_BRAKE, CMoway::led_action::ON);
}


void CmOwayDlg::OnBnClickedRadioLed2()
{
	PowerOffAllLEDs();
	miMoway.ChangeLEDState(CMoway::leds::LED_FRONT, CMoway::led_action::ON);
}


void CmOwayDlg::OnBnClickedRadioLed3()
{
	PowerOffAllLEDs();
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_GREEN, CMoway::led_action::ON);
}


void CmOwayDlg::OnBnClickedRadioLed4()
{
	PowerOffAllLEDs();
	miMoway.ChangeLEDState(CMoway::leds::LED_TOP_RED, CMoway::led_action::ON);
}


void CmOwayDlg::OnNMCustomdrawSliderRight(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Agregue aquí su código de controlador de notificación de control
	*pResult = 0;
}


void CmOwayDlg::OnNMCustomdrawSliderLeft(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Agregue aquí su código de controlador de notificación de control
	*pResult = 0;
}


void CmOwayDlg::OnNMReleasedcaptureSliderLeft(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	*pResult = 0;
}
