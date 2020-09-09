#include<windows.h>

//������ �������� ������� ����, ������� ����� ���������� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//��������� ������-��� ���������
char szProgName[] = "��� ���������";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w; //������ ��������� ��������� WNDCLASS

	//� �������� � ���������
	w.lpszClassName = szProgName; //��� ��������� - ��������� ����
	w.hInstance = hInstance; //������������� �������� ����������
	w.lpfnWndProc = WndProc; //��������� �� ������� ����
	w.hCursor = LoadCursor(NULL, IDC_ARROW); //��������� ������
	w.hIcon = 0; //������ � ��� �� ����� ����
	w.lpszMenuName = 0; //� ���� ���� �� �����
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���� ���� ����
	w.style = CS_HREDRAW | CS_VREDRAW; //����� - ���������������� �� � � �� �
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//���� �� ������� ���������������� ����� ���� - �������
	if (!RegisterClass(&w))
		return 0;

	//�������� ���� � ������, �������� ��������� CreateWindow
	hWnd = CreateWindow(szProgName, //��� ���������
		"��� ������ ���������!", //��������� ����
		WS_OVERLAPPEDWINDOW, //����� ���� - ���������������
		100, //��������� ���� �� ������ �� �
		100, //��������� �� �
		500, //������
		400, //������
		(HWND)NULL, //������������� ������������� ����
		(HMENU)NULL, //������������� ����
		(HINSTANCE)hInstance, //������������� ���������� ���������
		(HINSTANCE)NULL); //���������� �������������� ����������

		//������� ���� �� ������ �� �����
	ShowWindow(hWnd, nCmdShow);
	//������� ���������� ����
	UpdateWindow(hWnd);

	//���� ��������� ���������

	while (GetMessage(&lpMsg, hWnd, 0, 0)) { //�������� ��������� �� �������
		TranslateMessage(&lpMsg); //����������� ��������� ������ � �������
		DispatchMessage(&lpMsg); //������� ��������� ��������������� ������� ����
	}
	return(lpMsg.wParam);
}

//������� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc; //������ �������� ����������
	PAINTSTRUCT ps; //������ ��������� ��������� ������������ ������

	//���� ��������� ���������
	switch (messg)
	{
		//��������� ���������
	case WM_PAINT:
		//�������� ��������
		hdc = BeginPaint(hWnd, &ps);
		//����� �� ������ ���������� ���� �����:
		TextOut(hdc, 150, 150,  "����������, WIN 32 API!!!!", 26);
		//������������
		//��������� ����
		ValidateRect(hWnd, NULL);
		//����������� ��������
		EndPaint(hWnd, &ps);
		break;

		//��������� ������ - ���������� ����
	case WM_DESTROY:
		PostQuitMessage(0); //�������� ��������� ������ � ����� 0 - ���������� ����������
		break;

	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam)); //����������� ������� ���������� �� �������������
	}
	return 0;
}