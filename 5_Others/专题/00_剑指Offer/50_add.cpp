int Add(int num1, int num2)
{
    while (num2!=0) {
        int temp = num1^num2;//取其不同部分
        num2 = (num1&num2)<<1;//相同部分乘以2
        num1 = temp;
    }
    return num1;
}