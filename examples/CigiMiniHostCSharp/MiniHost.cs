using System.Threading;

namespace MiniHostBuild
{
    public class Program
    {
        static public MiniHostCIGI m_MiniHostCIGI;

        public static void Main(string[] args)
        {
            m_MiniHostCIGI = new MiniHostCIGI();

            while (true)
            {
                m_MiniHostCIGI.ProcessCIGI();
                Thread.Sleep(1000);
            }
        }
    }
}
