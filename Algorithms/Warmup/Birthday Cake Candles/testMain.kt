import org.junit.Test
import kotlin.test.assertEquals

data class TestCase(val given: Array<Int>, val want: Int) {}

class testMain {
    @Test
    fun testMain() {
        val testCase = arrayOf(
            TestCase(arrayOf(3, 2, 1, 3), 2),
        )

        testCase.forEach {
            val got = birthdayCakeCandles(it.given)
            assertEquals(it.want, got, "Test Failed")
        }
    }
}