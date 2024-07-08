using System;

namespace AnimalApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var k = new Animal("Binky");
            Console.WriteLine(k.GetName());
            k.Walk();
        }
    }
}
