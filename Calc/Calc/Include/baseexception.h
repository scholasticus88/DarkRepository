#pragma once

class LEXER_DLL_EXPORT CBaseException
{
public:
	CBaseException(const char * msg, long line, long column):
		m_lLine(line),
		m_lColumn(column),
		m_pMsg(NULL)
	{
		if (msg != nullptr)
		{
			m_pMsg = new char[strlen(msg) + 1];
			strncpy(m_pMsg, msg, strlen(msg));
			m_pMsg[strlen(msg)] = '\0';
		}
	}

	virtual ~CBaseException()
	{
		if (m_pMsg)
		{
			delete[] m_pMsg;
			m_pMsg = nullptr;
		}
	}

	virtual char* GetMessage() const { return m_pMsg; };
	virtual long  GetLine() const { return m_lLine; };
	virtual long  GetColumn() const { return m_lColumn; };

private:
	char* m_pMsg;
	long m_lLine;
	long m_lColumn;
};