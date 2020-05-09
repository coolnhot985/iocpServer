#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <WinSock2.h>
#include <iostream>
#include <process.h>

#define MAX_BUFFER		1024
#define SERVER_PORT		8000

using namespace std;

struct stSOCKETINFO {
	WSAOVERLAPPED	overlapped;
	WSABUF			dataBuf;
	SOCKET			socket;
	char			messageBuffer[MAX_BUFFER];
	int				recvBytes;
	int				sendBytes;
};

class IOCompletionPort {

public:
	IOCompletionPort();
	~IOCompletionPort();

	int		Initialize();
	void	StartServer();
	bool	CreateWorkerThread();
	void	WorkerThread();

private:
	stSOCKETINFO* m_pSocketInfo;		// ���� ����
	SOCKET			m_listenSocket;		// ���� ���� ����
	HANDLE			m_hIOCP;			// IOCP ��ü �ڵ�
	bool			m_bAccept;			// ��û ���� �÷���
	bool			m_bWorkerThread;	// �۾� ������ ���� �÷���
	HANDLE* m_pWorkerHandle;	// �۾� ������ �ڵ�
};