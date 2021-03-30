using NUnit.Framework;

namespace UnitTest
{
    public class Tests { 
    [Test]
    public void Test1()
    {
        double a = 1, b = 1, c = 1, d = 1, e = 1, f = -1.03;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "0";
        Assert.AreEqual(ans, expectedAns);
    }

    [Test]
    public void Test2()
    {
        double a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "0";
        Assert.AreEqual(ans, expectedAns);
    }
        [Test]
        public void Test3()
    {
        double a = 6, b = 3, c = 6, d = 3, e = 12, f = 12;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "1 -2 4";
        Assert.AreEqual(ans, expectedAns);
    }
        [Test]
        public void Test4()
    {
        double a = 0, b = 0, c = 6, d = 3, e = 0, f = 6;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "1 -2 2";
        Assert.AreEqual(ans, expectedAns);
    }
        [Test]
        public void Test5()
    {
        double a = 6, b = 3, c = 0, d = 0, e = 6, f = 0;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "1 -2 2";
        Assert.AreEqual(ans, expectedAns);
    }
    [Test]
    public void Test6()
    {
        double a = 1, b = 1, c = 3, d = 6, e = 3, f = 12;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "2 2 1";
        Assert.AreEqual(ans, expectedAns);
    }
        [Test]
        public void Test7()
    {
        double a = 1, b = 1, c = 3, d = 6, e = 3, f = 24;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "2 2 1";
        Assert.AreEqual(ans, expectedAns);
    }
        [Test]
        public void Test8()
    {
        double a = 3, b = 5, c = 4, d = 5, e = 3, f = 4;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "2 1 0";
        Assert.AreEqual(ans, expectedAns);
    }
        [Test]
        public void Test9()
    {
        double a = 5, b = 3, c = 5, d = 4, e = 3, f = 4;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "2 0 1";
        Assert.AreEqual(ans, expectedAns);
    }
    [Test]
    public void Test10()
    {
        double a = 1, b = 0, c = 0, d = 0, e = 1, f = 0;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "3 1";
        Assert.AreEqual(ans, expectedAns);
    }

    [Test]
    public void Test11()
    {
        double a = 0, b = 0, c = 1, d = 0, e = 0, f = 1;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "3 1";
        Assert.AreEqual(ans, expectedAns);
    }

    [Test]
    public void Test12()
    {
        double a = 1, b = 0, c = 1, d = 0, e = 1, f = 1;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "3 1";
        Assert.AreEqual(ans, expectedAns);
    }
    [Test]
    public void Test13()
    {
        double a = 0, b = 1, c = 0, d = 0, e = 1, f = 0;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "4 1";
        Assert.AreEqual(ans, expectedAns);
    }

    [Test]
    public void Test14()
    {
        double a = 0, b = 0, c = 0, d = 1, e = 0, f = 1;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "4 1";
        Assert.AreEqual(ans, expectedAns);
    }

    [Test]
    public void Test15()
    {
        double a = 0, b = 1, c = 0, d = 1, e = 1, f = 1;
        string ans = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expectedAns = "4 1";
        Assert.AreEqual(ans, expectedAns);
    }
    [Test]
    public void Test16()
    {
        double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        string answer = PPPP_Laba2.Program.SolveEquation(a, b, c, d, e, f);
        string expected = "5";
        Assert.AreEqual(answer, expected);
    }


}
}