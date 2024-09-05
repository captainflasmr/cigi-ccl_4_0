using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            var k = new Animal("Binky");
            Console.WriteLine(k.GetName());
            k.Walk();
        }
    }
}




