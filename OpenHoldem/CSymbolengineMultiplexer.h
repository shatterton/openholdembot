//*******************************************************************************
//
// This file is part of the OpenHoldem project
//   Download page:         http://code.google.com/p/openholdembot/
//   Forums:                http://www.maxinmontreal.com/forums/index.php
//   Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//*******************************************************************************
//
// Purpose: multiplexer functionality to support postfixes
//   like "dealer" or "last_caller_chair" instead of chair numbers.
//   This should be one of the very first symbol-engines to be called
//   to allow proper replacement of the postfix and a new query 
//   before other symbol engines try to handle this query.
//
//*******************************************************************************

#ifndef INC_CSYMBOLENGINEMULTIPLEXER_H
#define INC_CSYMBOLENGINEMULTIPLEXER_H

#include "CVirtualSymbolEngine.h"

class CSymbolEngineMultiplexer: public CVirtualSymbolEngine {
 public:
	CSymbolEngineMultiplexer();
	~CSymbolEngineMultiplexer();
 public:
	// Mandatory reset-functions
	void InitOnStartup();
	void ResetOnConnection();
	void ResetOnHandreset();
	void ResetOnNewRound();
	void ResetOnMyTurn();
	void ResetOnHeartbeat();
 public:
	// Public accessors
	bool EvaluateSymbol(const char *name, double *result, bool log = false);
	CString SymbolsProvided();
 private:
  inline bool FastExitOnLastCharacter(int last_character_of_symbol);
  void Multiplex(const char* complete_name, int multiplex_index, double* result);
};

extern CSymbolEngineMultiplexer *p_symbol_engine_multiplexer;

#endif INC_CSYMBOLENGINEMULTIPLEXER_H