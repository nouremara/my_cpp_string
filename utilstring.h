// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own string Class

/**========================================================================
 * @file      utilstring.h
 * @brief     implementation of own string class.
 * @author    Nour Ahmed
 * @email     nahmed@stud.hs-bremen.de, nour
 * @repo      https://github.com/nouremara/cpp_mystring
 * @createdOn 23.11.2022
 * @version   1.0.0
 * @description
 *
 * This file presents an implementation of a class named string.
 * This class behavior will be similar and compatible to the std::string.
 * This file contains the prototypes for the class, its methods and eventually
 * any macros, constants, or global variables you will need to use it.
 *========================================================================**/

#ifndef UTILSTRING_H
#define UTILSTRING_H

#include <cstddef>
#include <iostream>
#include <string>

namespace util {
/** Initially, the class shall provide memory for 10 printable characters
* Note: value is implementation detail and subject to change
*/
#define INITIAL_SIZE 10 

	/**
	* @brief Implementation of of own string class.
	*
	* @description
	*
	* This class presents own string class implementation. This class behavior 
	* will be similar and compatible to the std::string.
	*/
	class string {
		char* internal_buffer;
		size_t buffer_size;
		// size_t string_size;

	public:
		/*=========================================================================*
		 *                         Constructors                                    *
		 *=========================================================================*/
		 /** default constructor with empty initialization */
		string();

		/** Constructor with a given initial size
		 *  @param intialSize  number of bytes (characters) to intialize the string with.
		 */
		string(size_t intialSize);

		/** Constructor with parameter const char*
		 *  @param charArray  primitive C-string to intialize the string with.
		 */
		string(const char* charArray);

		/** Constructor with parameter std::string
		  * @param std_string  c++ std::string to intialize the string with.
		 */
		string(const std::string& std_string);

		/** Copy constructor: Creates a deep copy of a passed string
		  * @param std_string  c++ util::string to intialize the string with.
		 */
		string(const string&);

		/*=========================================================================*
		 *                         Destructor                                      *
		 *=========================================================================*/
		 /** Destructor to do the final cleanup and memory deallocation */
		~string(void);

		/*=========================================================================*
		 *                         Methods                                         *
		 *=========================================================================*/
		/**
		* @brief Ensure a string is initialized before using it.
		* 
		* @details
		* initialize an empty string with buffer size of the given length.
		* 
	    * @param length  number of bytes (characters) to allocate in memory for the internal buffer.
	    */
		void intialize_string(size_t length = 0);
		//-------------------------------------------------------------

		/**
		* @brief Deep copy of primitive C-string into the string internal buffer.
		* 
		* @details
		* This function realizes a design and implementation of a concept to extend
		* the internal memory if util::string has to store more than its current 
		* allocated buffer size.
		* note that the function copy the passed char array starting from the
		* startPosition (i.e. it can write starting from any position in the internal
		* string buffer) startPosition default is 0
		* 
		* @param rawChar		pointer to the primitive C-string to copy to the 
		*                       internal buffer.
		* @param startPosition  start position (in the target buffer) to start 
		*                       copying the source string to [default: 0].
		*/
		void deepCopy(const char* rawChar, size_t startPosition = 0);
		//-------------------------------------------------------------

		/**
		* @brief Returns a newly constructed util::string object with a portion of the string.
		* 
		* @details
		* The substring is the portion of the object that starts at character
		* position start_position and spans len characters (or until the end of
		* the string, whichever comes first).
		* 
		* @param [in]  start_position  start position in the source string.
		* @param [in]  length          specifies the amount of characters of the new util::string to be returned.
		* @return                      Returns a substring object of type util::string which starts at pos
		*/
		string substr(size_t start_position, size_t length);
		//-------------------------------------------------------------

		/**
		* @brief Allows raw access to the internal C-string (through its char* pointer)
		*
		* @details
		*
		* Returns a pointer to an array that contains a null-terminated sequence of 
		* characters (i.e., a C-string) representing the current value of the string
		* object.
		* @return Returns a pointer to an array that contains a null-terminated 
		          sequence of characters.
		*/
		char* c_str() const;
		//-------------------------------------------------------------

		/**
		* Compares two char * strings lexicographically
		* This function is my own implementation of the std::strcmp() function.
		* Note this function performs a binary comparison of the ASCII code of the
		*characters.
		*
		* @param s1   pointer to the primitive C string to be compared.
		* @param s2   pointer to the primitive C string to be compared with.
		* @return     an integral value indicating the relationship between the strings
		* @retval < 0 The first character that does not match has a lower value in s1 than in s2
		* @retval 0   The contents of both strings are equal 
		* @retval > 0 The first character that does not match has a greater value in s1 than that in in s2
		*/
		static int compare(const char* s1, const char* s2);
		//-------------------------------------------------------------

		/**
		 * Clears your string object
		 * Erases the contents of the string, which becomes an empty string (with
		 * a length of 0 characters).
		 */
		void clear();
		//-------------------------------------------------------------


		/**
		 * Get the amount of characters of a raw char* string excluding the terminating \0.
		 */
		static size_t rawSize(const char* rawChar);
		//-------------------------------------------------------------

		/**
		 * Returns the amount of characters of your string excluding \0.
		 * Might be smaller than the actual reserved memory.
		*/
		size_t length() const;
		size_t size() const; /*!< Get the length of the string synonyme to length()*/
			//-------------------------------------------------------------

		/**
		 * Returns the size of the storage space currently allocated for the
		 * string, expressed in terms of bytes.
		 */
		size_t capacity() const;
		//-------------------------------------------------------------

		/*=========================================================================*
		 *                         Operators                                       *
		 *=========================================================================*/

		/**
		* Operator + such that string, std::string and (const) char* can be added
		*/
		string operator+(const string& rhsString);
		string operator+(const std::string& rhsString);
		string operator+(const char* strInstance);
		//-------------------------------------------------------------

		string& operator+=(const string& rhsString);
		string& operator+=(const std::string& rhsString);
		string& operator+=(const char* strInstance);
		//-------------------------------------------------------------

		/** Assigns a new value to the string, replacing its current contents.*/
		string& operator=(const string& rhsString);
		string& operator=(const char* rhsCharArray);
		string& operator=(const std::string& rhsString);
		//-------------------------------------------------------------

		/** 
		* Compares the contents of a string with another string, std::string, or 
		* a null - terminated array of char for equality.
		*/
		bool operator==(const string& rhsString);
		bool operator==(const std::string& rhsString);
		bool operator==(const char* charArray);
		//-------------------------------------------------------------

		/**
		* Compares the contents of a string with another string, std::string, or
		* a null - terminated array of char for non-equality.
		*/
		bool operator!=(const string& rhsString);
		bool operator!=(const std::string& rhsString);
		bool operator!=(const char* charArray);
		//-------------------------------------------------------------

		/** Returns a reference to the character at position pos in the string.*/
		char& operator[](size_t position);

		/*=========================================================================*
		 *             Non-member function overloads                               *
		 *=========================================================================*/
		 // Free operator methods for the cases util::string is on the RHS
		 // Friendship enables access to private members

		/** Insert string into stream*/
		friend std::ostream& operator<<(std::ostream& iostream, const util::string& myString);


		/**
		* Compares the contents of a string with another string, std::string, or
		* a null - terminated array of char for equality.
		* For the cases util::string is on the RHS.
		*
		* @relatesalso util::string
		*/
		friend bool operator==(const std::string& lhsString, const util::string& rhsString);
		friend bool operator==(const char* lhsCharArray, const util::string& rhsString);

		/**
		* Compares the contents of a string with another string, std::string, or
		* a null - terminated array of char for non-equality.
		* For the cases util::string is on the RHS.
		*
		* @relatesalso util::string
		*/
		friend bool operator!=(const std::string& lhsString, const util::string& rhsString);
		friend bool operator!=(const char* lhsCharArray, const util::string& rhsString);
	};


	/*=========================================================================*
	 *             Some Utility functions                                      *
	 *=========================================================================*/

	/**
	* @brief Deep copy of primitive C-string into another primitive C-string.
	*
	* @details
	* This function realizes a design and implementation of a concept to low-level
	* copy and fill a primitive C-string with another primitive C-string starting 
	* from a given start position and with a desired number of character from the 
	* sourrce string.
	* note that the function copy the passed char array starting from the
	* startPosition (i.e. it can write starting from any position in the 
	* destination string buffer) startPosition default is 0
	*
	* @relatesalso util::string
	* @param rawCharTarget		pointer to the destination primitive C-string to copy to
	* @param rawCharSource		pointer to the source primitive C-string to copy from
	* @param destStartPosition	start position(in the target buffer) to start
	*							copying the source string to [default: 0].
	* @param srcEndPosition		end position (in the source string) to stop at 
	*							[default: to the end of the source array].
	*/
	void deepCopy(char* rawCharTarget, 
				  const char* rawCharSource,
				  size_t destStartPosition = -1, 
				  size_t srcEndPosition = -1);
	//-----------------------------------------------
	
	/** @brief to print a nicely formatted and colored text header to the terminal*/
	void printHeader(const char* text);
	
	/** @brief to print a nicely formatted and colored text sub header to the terminal*/
	void printSubHeader(const char* text);
	
	/** @brief to print a nicely formatted and colored text title header to the terminal*/
	void printTestCase(const char* text);

} // namespace util

#endif /* UTILSTRING_H */
