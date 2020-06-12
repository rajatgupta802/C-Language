int  sum (int count,...) 
{
 va_list ap;
    int i, n;
    va_start(ap, count);
    n = 0;
    for (i=0;i<count;i++){
        n += va_arg(ap, int);
     }
    va_end(ap);
    return n;
}

int min(int count,...) 
{
 va_list ap;
    int i, current, minimum;
    va_start(ap, count);
    minimum = 1000001;
    for (i=0;i<count;i++){
        current = va_arg(ap, int);
        if (current < minimum)
            minimum = current;
    }
    va_end(ap);
    return minimum;

}

int max(int count,...)
{
  va_list ap;
    int i, current, maximum;
    va_start(ap, count);
    maximum = 0;
    for (i=0;i<count;i++){
        current = va_arg(ap, int);   
        if (current > maximum)
            maximum = current;
    }
    va_end(ap);
    return maximum;

}
