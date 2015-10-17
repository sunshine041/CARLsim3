#ifndef _USER_ERRORS_H_
#define _USER_ERRORS_H_

#include <string>		// std::string

/*!
 * \brief Static Class for handling user errors
 *
 * This static class handles all possible errors that can be generated by the user. Such errors include incorret calls
 * of CARLsim core functions, conceptual/chronological errors in setting up a network, etc.
 * All these errors are supposed to be fatal; that is, an error message will be printed and CARLsim will exit.
 */
class UserErrors {
public:
	// +++++ PUBLIC PROPERTIES ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

	/*!
	 * \brief an enum of all possible error codes
	 *
	 * This enum contains all the different error codes that are possible (in alphabetical order).
	 * Whenever an error is thrown, it has to be assigned one of these values.
	 * There is also type UNKNOWN for unspecified errors.
	 */
	enum errorType {
		ALL_NOT_ALLOWED,		//!< keyword ALL is not allowed for this variable
		CAN_ONLY_BE_CALLED_IN_MODE,	//!< function can only be called in certain mode
		CAN_ONLY_BE_CALLED_IN_STATE,//!< function can only be called in certain state
		CANNOT_BE_CALLED_IN_MODE,	//!< function cannot be called in certain mode
		CANNOT_BE_CALLED_IN_STATE,	//!< function cannot be called in certain state
		CANNOT_BE_IDENTICAL,	//!< parameters cannot be identical
		CANNOT_BE_NEGATIVE,		//!< parameter cannot have negative value (opposite to "must be", but includes zero)
		CANNOT_BE_NULL,			//!< parameter cannot have NULL value
		CANNOT_BE_LARGER,		//!< parameter cannot have larger vaule than some vaule
		CANNOT_BE_SMALLER,		//!< parameter cannot have smaller vaule than some vaule
		CANNOT_BE_OFF,			//!< parameter cannot be off
		CANNOT_BE_ON,			//!< parameter cannot be on
		CANNOT_BE_POSITIVE,		//!< parameter cannot have positive value (opposite to "must be", but includes zero)
		CANNOT_BE_SET_TO,		//!< parameter cannot be set to
		CANNOT_BE_UNKNOWN, 		//!< parameter cannot be of type UNKNOWN
		CANNOT_BE_ZERO,			//!< parameter cannot be zero
		EXCEED_COMP_CONNECTION_LIMIT,	//!< this compartmental connection exceeds the group's limit for compartmental connections
		FILE_CANNOT_CREATE,		//!< could not create a file
		FILE_CANNOT_OPEN,		//!< could not open file
		IS_DEPRECATED,			//!< deprecated function
		MUST_BE_CALLED,			//!< must be called
		MUST_BE_IDENTICAL,      //!< parameters must be identical
		MUST_BE_IN_RANGE,		//!< parameter must be in some range
		MUST_BE_LOGGER_CUSTOM,	//!< must be in custom logger mode
		MUST_BE_NEGATIVE,		//!< parameter must have negative value
		MUST_BE_OFF,			//!< parameter must be off
		MUST_BE_ON,				//!< parameter must be on
		MUST_BE_POSITIVE,		//!< parameter must have positive value
		MUST_BE_SET_TO,			//!< parameter must be set to
		MUST_BE_LARGER,			//!< parameter must be larger than
		MUST_BE_SMALLER,		//!< parameter must be smaller than
		MUST_BE_ZERO,           //!< parameter must be 0
		MUST_HAVE_SAME_SIGN,	//!< some parameters must have the same sign
		NETWORK_ALREADY_RUN,	//!< function cannot be called because network has already bun run
		REPEATED_COMP_CONNNECTION,	//!< this compartmental connection is either identical or a reverse of an existing compartmental connection
		SYNAPSE_COMP_CONNECTION,	//!< cannot create a synaptic and compartmental connection between two groups
		UNKNOWN_GROUP_ID,		//!< the specified group id is unknown
		UNKNOWN,				//!< an unknown error
		WRONG_NEURON_TYPE		//!< function cannot be applied to neuron type
	};


	// +++++ PUBLIC METHODS +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

	/*!
	 * \brief simple wrapper for assert statement
	 *
	 * This function evaluates a certain statement to true or false, and if it false, it will throw an error.
	 * There is a standard error message for each user error type. This message can be extended by using a prefix and/or
	 * a suffix. For example: errorIfAssertionFails=CANNOT_BE_IDENTICAL, errorMsgPrefix="A", errorMsgSuffix="B" will
	 * print "A cannot be identical to B.".
	 * \param[in] statement					the logical statement to evaluate
	 * \param[in] errorIfAssertionFails		the type of error to throw if assertion fails (from enum errorType)
	 * \param[in] errorFunc					a string to indicate the location where the error occured
	 * \param[in] errorMsgPrefix			a prefix for the error message
	 * \param[in] errorMsgSuffix 			a suffix for the error message
	 */
	static void assertTrue(bool statement, errorType errorIfAssertionFails, std::string errorFunc,
								std::string errorMsgPrefix="", std::string errorMsgSuffix="");

//	static void userAssertNonZero();
//	static void userAssertNonNegative();

private:
	// +++++ PRIVATE METHODS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

	/*!
	 * \brief simple wrapper for displaying an error message
	 *
	 * This function generates a standard error message for a certain error type, displays the message, and aborts
	 * the process.
	 * \param[in] errorFunc 	a string to indicate the location where the error occurred
	 * \param[in] error 		the type of error to throw (from enum errorType)
	 */
	static void throwError(std::string errorFunc, errorType error, std::string errorMsgPrefix="",
		std::string errorMsgSuffix="");
};

#endif
