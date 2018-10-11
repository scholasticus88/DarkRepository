//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.7.1
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from C:\Src\dark_repository\Evaluator\\Evaluator.g4 by ANTLR 4.7.1

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using IToken = Antlr4.Runtime.IToken;

/// <summary>
/// This interface defines a complete generic visitor for a parse tree produced
/// by <see cref="EvaluatorParser"/>.
/// </summary>
/// <typeparam name="Result">The return type of the visit operation.</typeparam>
[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.7.1")]
[System.CLSCompliant(false)]
public interface IEvaluatorVisitor<Result> : IParseTreeVisitor<Result> {
	/// <summary>
	/// Visit a parse tree produced by <see cref="EvaluatorParser.prog"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitProg([NotNull] EvaluatorParser.ProgContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>AssignmentCommand</c>
	/// labeled alternative in <see cref="EvaluatorParser.cmd"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAssignmentCommand([NotNull] EvaluatorParser.AssignmentCommandContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>ExpressionCommand</c>
	/// labeled alternative in <see cref="EvaluatorParser.cmd"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitExpressionCommand([NotNull] EvaluatorParser.ExpressionCommandContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>BrackExpr</c>
	/// labeled alternative in <see cref="EvaluatorParser.expr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitBrackExpr([NotNull] EvaluatorParser.BrackExprContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>MulDiv</c>
	/// labeled alternative in <see cref="EvaluatorParser.expr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitMulDiv([NotNull] EvaluatorParser.MulDivContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>AddSub</c>
	/// labeled alternative in <see cref="EvaluatorParser.expr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitAddSub([NotNull] EvaluatorParser.AddSubContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>VariableFactor</c>
	/// labeled alternative in <see cref="EvaluatorParser.expr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitVariableFactor([NotNull] EvaluatorParser.VariableFactorContext context);
	/// <summary>
	/// Visit a parse tree produced by the <c>NumberFactor</c>
	/// labeled alternative in <see cref="EvaluatorParser.expr"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNumberFactor([NotNull] EvaluatorParser.NumberFactorContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="EvaluatorParser.factor"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitFactor([NotNull] EvaluatorParser.FactorContext context);
}