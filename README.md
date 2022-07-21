<h1>Printf without bonus part</h1>
<p>The C library function int printf(const char *format, ...) sends formatted output to stdout. This standard function is a part of stdio.h&nbsp;</p>
<h3>Example</h3>
<p>printf(&quot;%s is over %d years old.\n&quot;,&quot;TechOnTheNet.com&quot;,10);</p>
<p><br></p>
<p>Result:&nbsp;TechOnTheNet.com is over 10 years old.</p>
<p>For basic printf we need these flags:</p>
<ul>
    <li>
        <p>%c&nbsp;Prints a single character.&nbsp;</p>
    </li>
    <li>
        <p>%s Prints a string (as defined by the common C convention).&nbsp;</p>
    </li>
    <li>
        <p>%p The void * pointer argument has to be printed in hexadecimal format. %d Prints a decimal (base 10) number.&nbsp;</p>
    </li>
    <li>
        <p>%i Prints an integer in base 10.&nbsp;</p>
    </li>
    <li>
        <p>%u Prints an unsigned decimal (base 10) number.&nbsp;</p>
    </li>
    <li>
        <p>%x Prints a number in hexadecimal (base 16) lowercase format.&nbsp;</p>
    </li>
    <li>
        <p>%X Prints a number in hexadecimal (base 16) uppercase format.&nbsp;</p>
    </li>
    <li>
        <p>%% Prints a percent sign.&nbsp;</p>
    </li>
</ul>
<h3>Tips</h3>
<p>You can read this articles for better understanding:</p>
<p><a href="https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm">https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm</a></p>
<p><a href="https://www.techonthenet.com/c_language/standard_library_functions/stdio_h/printf.php">https://www.techonthenet.com/c_language/standard_library_functions/stdio_h/printf.php</a>&nbsp;</p>
<p><a href="https://www.educative.io/answers/how-to-use-printf-in-c">https://www.educative.io/answers/how-to-use-printf-in-c</a>&nbsp;</p>
<p><br></p>
<h3>Also I used this code examples:</h3>
<p>&nbsp;<a href="https://codeberg.org/UncleReaton/ft_printf">https://codeberg.org/UncleReaton/ft_printf</a></p>
<p><a href="http://www.firmcodes.com/write-printf-function-c/">http://www.firmcodes.com/write-printf-function-c/</a></p>
<p><a href="https://github.com/settleformore/ft_printf">https://github.com/settleformore/ft_printf</a></p>
<p>These examples are more difficult, my variant is easier:)&nbsp;</p>
<p><a href="https://github.com/Annabel-13/ft_printf">https://github.com/Annabel-13/ft_printf</a></p>
<p><br></p>
<h3>Also before start your coding you have to figure out with multiple arguments and &nbsp;va_list for working with them.</h3>
<p>https://c-for-dummies.com/blog/?p=3398</p>
<p>https://www.cprogramming.com/tutorial/c/lesson17.html</p>
<h2>ft_printf.c</h2>
<p>There are three functions:&nbsp;</p>
<ol>
    <li>
        <p>&nbsp;ft_printf</p>
    </li>
    <li>
        <p>check_format</p>
    </li>
    <li>
        <p>Standard ft_putchar (we did it on Piscine or in libft)</p>
    </li>
</ol>
<h3>ft_printf</h3>
<p>It&rsquo;s your main engine.</p>
<p>You need:</p>
<ul>
    <li>
        <p>standard counter</p>
    </li>
    <li>
        <p>va_list for array of multiple arguments&nbsp;</p>
    </li>
    <li>
        <p>variable for global result</p>
    </li>
    <li>
        <p>&nbsp;variable for buffer. You will use it for connection between your flags functions.&nbsp;</p>
    </li>
</ul>
<h3>Tips</h3>
<p>You can write ft_printf without variable for buffer, but in my variant it&rsquo;s important, because without that I couldn&rsquo;t combine all results</p>
<p><br></p>
<p>Start work with your va_list with va_start.</p>
<p>Store in your variables start values.</p>
<p>For sorting your&nbsp;format(first argument of printf) just start while loop till your format exists.</p>
<p>Inside your while you need 2 conditions:</p>
<ul>
    <li>
        <p>If your char in format is % - you add 1 extra char and begin your next function check_format&nbsp;</p>
    </li>
    <li>
        <p>Else - store in result printing your format with putchar</p>
    </li>
</ul>
<p>This function return result</p>
<p><br></p>
<h3>check_format</h3>
<p>In arguments for this function you use your format, va_list with arguments, counter with current number of iterations, buffer</p>
<p><br></p>
<p>Here you just check next char,if it&apos;s one of our flags or not:</p>
<p>c - just print this char with putchar</p>
<p>% - the same ,just print it</p>
<p>s - special function for printing string</p>
<p>p - special function for printing pointer</p>
<p>d - special function for printing numbers</p>
<p>i - the same function for printing numbers</p>
<p>u - special function for printing decimal numbers</p>
<p>X and x - special function for printing hexadecimal numbers</p>
<p>Further I will explain the main concept of necessary functions. In each of them you use your va_list and buffer&nbsp;</p>
<p><br></p>
<h2>ft_print_str.c</h2>
<p>Here your va_arg waits type void *.</p>
<p>You need 2 conditions:</p>
<p>If your va_arg(firstly,read about va_list work!) equal null - just print &quot;(null)&quot; with putstr(the same as putchar,but with while inside for printing whole string)</p>
<p>Else just print your va_arg with putstr</p>
<p><br></p>
<h2>print_pointer.c</h2>
<p>Here your va_arg waits type unsigned long.</p>
<p>In this part you need a special error answer for a pointer.&nbsp;</p>
<p>For the Mac system it&apos;s &quot;0x0&quot;. So if your va_arg is null,just print this error answer with putstr.</p>
<p>In another case (when your va_arg isn&apos;t null). You have to print the beginning of each pointer address - &quot;0x&quot; with putstr and after that use special function ft_putnbr_base_ul ( I will describe it later)</p>
<p><br></p>
<h2>print_nmb.c&nbsp;</h2>
<p>Here your va_arg waits type int.</p>
<p>You can find function for printing numbers in our Piscine projects ( If I remember right it&apos;s C01)</p>
<p>This function consist of two parts:</p>
<p>For numbers lower than 9 and more than 9.</p>
<p>For less than 9 - just print it with putchar adding &apos;0&apos; (char transformation)</p>
<p>For more than 9 - divide it with 10 in recursion and use modulo with 10</p>
<p>Also you need special condition for negative numbers (just print &apos;-&apos; with putchar and return this number as a positive number)</p>
<h2>print_nmb_u.c</h2>
<p>Also waits int as va_arg&nbsp;</p>
<p>Actually the same with print_nmb,but here as argument we use unsigned int(diapason is wider). So because of this we need a separate function.</p>
<p><br></p>
<h3>print_hexa_nmb.c</h3>
<p>Here your va_arg waits type unsigned long (again wider diapason).</p>
<p>Here we use the function&nbsp;ft_putnbr_u&nbsp;for uppercase and lowercase hexadecimal bases. In this function we just change the 16-numbers base (&quot;0123456789ABCDEF&quot; and &quot;0123456789abcdef&quot;). According to our base we print the symbols from base with putchar. Number of our symbol depends on our input number.&nbsp;</p>
<p>If the number is bigger than the length of the base(in our case, it&apos;s 16) we divide it and modulo 16.</p>
<h3>Tips</h3>
<p>More details</p>
<p><a href="https://www.tutorialspoint.com/hexadecimal-number-system">https://www.tutorialspoint.com/hexadecimal-number-system</a>&nbsp;</p>
<p><br></p>
<p>As well we can use lowercase or uppercase functions from libft,but I didn&apos;t understand how to type cast it right. But it&apos;s possible&nbsp;</p>
<p><br></p>
<p>That&apos;s all,folks:)</p>
<p><br></p>
<p><br></p>
<p><br></p>
<p><br></p>
<p><br></p>
<p><br></p>
