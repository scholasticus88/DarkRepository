using System;
using System.IO;
using Antlr4.Runtime;
using Antlr4.Runtime.Tree;

namespace Evaluator
{
    class Program
    {
        static void Main(string[] args)
        {
            EvaluatorLexer lexer = new EvaluatorLexer(new AntlrFileStream(args[0]));

            CommonTokenStream tokenStream = new CommonTokenStream(lexer);

            EvaluatorParser parser = new EvaluatorParser(tokenStream);

            IParseTree tree = parser.prog();

            MathVisitor mv = new MathVisitor();
            mv.Visit(tree);
            int i = 0;
        }
    }
}
