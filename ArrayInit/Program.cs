using System;
using System.Text;
using Antlr4.Runtime;
using Antlr4.Runtime.Tree;

namespace App
{
    class Program
    {
        static void Main(string[] args)
        {
            AntlrInputStream input = new AntlrInputStream(args[0]);

            ArrayInitLexer lexer = new ArrayInitLexer(input);

            CommonTokenStream tokens = new CommonTokenStream(lexer);

            ArrayInitParser parser = new ArrayInitParser(tokens);

            IParseTree tree = parser.list();
            Console.WriteLine(tree.ToStringTree(parser));
            Console.WriteLine("");

            ParseTreeWalker walker = new ParseTreeWalker();
            walker.Walk(new ValueConvertor(), tree);
            Console.WriteLine("");
        }
    }
}
