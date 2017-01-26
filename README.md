# Trinomial_Pricer
Overview
This program can be used to Price European call and put options. Typically, one might do so by using a Binomial modelling of stock prices or perhaps Black-Scholes model but this program bases its calculations upon a Trinomial model. We say at each time step n = 0,1,2, …N a stock could either move upwards, downwards or somewhere in between these two. We call these Possibilities U, D and M respectively. Based upon this assumption we can say that a stock has value:

S(n,i,j)=(1+U)^i (1+M)^j (1+D)^((n-i-j))

Where i, j and (n - i - j) denote the number of up-movements, mid-movements and down-movements of the stock respectively.


We can then use the Cox-Ross-Rubenstein procedure with backward induction to find the prices of the option H(n,i,j) for each combination of movements at each time step n. The formula is as follows:

H(n,i,j)=(q_U H(n+1,i+1,j)+q_M H(n+1,i,j+1)+q_D H(n+1,i,j))/((1+R))

where q_U,q_M,q_D are the risk neutral probabilities and 1+R is the rate of growth of a risk free security. 




------------------------------------------------------------------------------
						Complilation


Easy compilation in code blocks. Just clone then open .cbp file.

-------------------------------------------------------------------------------
						How to use .exe
						
1.)Compile code and run the resulting .exe. A console will appear on screen that will prompt you to enter a value for S_0 (the initial value of the stock). Do so and press enter.

2.)	The program will proceed to ask for the values of U, M, D, R, and V where V is the volatility of the asset and U, M, D and R are the up-movement mid-movement, down-movement and risk free interest rate respectively. Type the value asked for into the keyboard and Hit enter.

3.)	The program will then check whether the data you supplied is illegal and/or there is arbitrage. If either of these conditions are met the program will terminate.

4.)	If the data is legal and there is no arbitrage the program will prompt you for the expiry time of the call option N followed by the strike price K. As above type in the value prompted for then hit enter.

5.)	The program will then print to the screen the initial call option Price in the program console.

6.)	Finally, 7.) is repeated but this time for the put option. Again the price is printed to the screen in the console.

7.)	Hit the enter key and the program will now close.
						


