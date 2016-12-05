#ifndef DEBUG_H
#define	DEBUG_H

#include <fstream.h>

class CDebug
{
public:
	CDebug(CString dbgFileName);
	~CDebug();

	void ShowDebug(CString info);

private:
	ofstream *m_pDbgStream;
};


#endif //DEBUG_H