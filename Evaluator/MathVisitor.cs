using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Antlr4.Runtime.Misc;

namespace Evaluator
{
    class MathVisitor : EvaluatorBaseVisitor<int>
    {
        private Dictionary<string, int> values = new Dictionary<string, int>();

        public override int VisitProg(EvaluatorParser.ProgContext context)
        {
            return base.VisitProg(context);
        }

        public override int VisitAddSub(EvaluatorParser.AddSubContext context)
        {
           int i0 = Visit(context.expr(0));
           int i1 = Visit(context.expr(1));

            if (context.op.Type == EvaluatorParser.PLUS)
                return i0 + i1;
            return i0 - i1;
        }

        public override int VisitMulDiv(EvaluatorParser.MulDivContext context)
        {
            int i0 = Visit(context.expr(0));
            int i1 = Visit(context.expr(1));

            if (context.op.Type == EvaluatorParser.MUL)
                return i0 * i1;
            return i0 / i1;
        }

        public override int VisitNumberFactor(EvaluatorParser.NumberFactorContext context)
        {
            int i = int.Parse(context.NUM().GetText());

            bool bFactor = VisitFactor(context.factor()) != 0;
            if (bFactor)
            {
                i = Factorial(i);
            }

            return i;
        }

        public override int VisitFactor(EvaluatorParser.FactorContext context)
        {
            if (context.FACTOR() != null)
                return 1;

            return 0;
        }

        public override int VisitBrackExpr(EvaluatorParser.BrackExprContext context)
        {
            int i = Visit(context.expr());

            bool bFactor = VisitFactor(context.factor()) != 0;
            if (bFactor)
            {
                i = Factorial(i);
            }

            return i;
        }

        public override int VisitVariableFactor(EvaluatorParser.VariableFactorContext context)
        {
            string id = context.ID().GetText();

            if (!values.ContainsKey(id))
            {
                throw new Exception("Unknown id.");
            }

            bool bFactor = VisitFactor(context.factor()) != 0;

            int i = values[id];
            if (bFactor)
            {
                i = Factorial(i);
            }

            return i;
        }

        public override int VisitAssignmentCommand(EvaluatorParser.AssignmentCommandContext context)
        {
            string id = context.ID().GetText();

            values[id] = Visit(context.expr());

            return values[id];
        }

        public override int VisitExpressionCommand(EvaluatorParser.ExpressionCommandContext context)
        {
            return Visit(context.expr());
        }

        private int Factorial(int i)
        {
            int n = i;
            i -= 1;
            while (i > 0)
            {
                n *= i;
                i--;
            }

            return n;
        }
    }
}
