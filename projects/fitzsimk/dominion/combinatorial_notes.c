
// iterative fuzzing: cards in hand
//  Its effectiveness is based on the observation that software failures often involve interactions between parameters.
//Interaction Rule: Most failures are induced by single factor faults or by the joint combinatorial
//effect (interaction) of two factors, with progressively fewer failures induced by interactions
//between three or more factors

• error: a mistake made by a developer. This could be a coding error or a
misunderstanding of requirements or specification.
• fault: a difference between an incorrect program and one that correctly implements a
specification. An error may result in one or more faults.
• failure: a result that differs from the correct result as specified. A fault in code may
result in zero or more failures, depending on inputs and execution path. 
There are basically two approaches to combinatorial testing – use combinations of
configuration parameter values, or combinations of input parameter values. 