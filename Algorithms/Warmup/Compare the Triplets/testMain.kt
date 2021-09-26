import org.junit.Test
import kotlin.test.assertEquals

data class TestCase(val given: Array<Int>, val want: Int) {}

class testMain {
    @Test
    fun testMain() {
        val testCase = arrayOf(
            TestCase(arrayOf(arrayOf(5, 6, 7), (3, 6, 10)), arrayOf(1, 1)),
            TestCase(arrayOf(arrayOf(17, 28, 30), (99, 16, 8)), arrayOf(2, 1)),
        )

        testCase.forEach {
            val got = compareTriplets(it.given)
            assertEquals(it.want, got, "Test Failed")
        }
    }
}
