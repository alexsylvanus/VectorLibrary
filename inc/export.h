/*
 * File: export.h
 * Author: Alex Sylvanus
 * Description: Defines the LIBRARY_API macro for dll exporting on windows
 * 
 */

// Begin header
#ifndef INC_EXPORT_H_
#define INC_EXPORT_H_

// Set LIBRARY_API macro
#ifdef _WIN32
	#ifdef LIBRARY_EXPORTS
		#define LIBRARY_API __declspec(dllexport)
	#else
		#define LIBRARY_API __declspec(dllimport)
	#endif
#else
#define LIBRARY_API
#endif

#endif /* INC_EXPORT_H_ */