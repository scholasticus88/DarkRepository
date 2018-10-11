using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Antlr4.Runtime.Misc;

namespace App
{
    class ValueConvertor : ArrayInitBaseListener
    {
        public override void EnterList(ArrayInitParser.ListContext context)
        {
            Console.Write("\"");
        }

        public override void ExitList(ArrayInitParser.ListContext context)
        {
            Console.Write("\"");
        }

        public override void EnterPart(ArrayInitParser.PartContext context)
        {
            string s = context.GetText();

            if (context.ChildCount > 0)
            {
                if (context.INT() != null)
                {
                    int val = int.Parse(s);
                    Console.Write("0x"+val.ToString("X"));
                    Console.Write(", ");
                }
                else
                {
                    base.EnterPart(context);
                }
            }
        }
    }
}
