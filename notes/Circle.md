# **Circle**

$$
(x-x_c)^2 + (y-y_c)^2 = r^2
$$

$x^2 + y^2 = r^2$ if the circle is at center (0,0) and $r$ = radius.

---

### Midpoint Circle Algorithm

$$
f_{circ}(x, y) = x^2 + y^2 - r^2
$$

**If**

- $f_{circ}(x, y)$ < 0, (x, y) is inside the boundary.
- $f_{circ}(x, y)$ = 0, (x, y) is on the boundary.
- $f_{circ}(x, y)$ > 0, (x, y) is outside the boundary.

**Let**, there is a point plotted in $(x_k, y_k)$. The nex point can either $(x_k + 1, y_k)$ or $(x_k + 1, y_k - 1)$.

**The decision parameter $p_k$:** The decision parameter at

$$
p_k = f_{circ}\left(x_k + 1, y_k - \frac{1}{2}\right)\\
= (x_k + 1)^2 + \left(y_k - \frac{1}{2} \right)^2 - r^2
$$

Now, calculate $p_{k + 1}$

$$
\begin{align*}
p_{k + 1} &= f_{circ}\left(x_{k + 1} + 1, y_{k + 1} - \frac{1}{2}\right)\\
&= [(x_k + 1) + 1]^2 + \left(y_{k + 1} - \frac{1}{2} \right)^2 - r^2\\
p_{k+1} &= p_k + 2(x_k + 1) + (y_{k+1}^2 - y_k^2) - (y_{k+1} - y_k) + 1
\end{align*}
$$

where $y_{k+1}$ is either $y_k$ or $y_{k − 1}$, depending on the sign of $p_k$.

---

<br/>
<br/>

**If,** $\space p < 0$, then the midpoint is inside the circle, so the next chosen point will be $(x_k + 1, y_k)$.

**Else,** the midpoint is outside or on the circle, the point $(x_k + 1, y_k - 1)$ will be chosen.

**So, we get:**

**If** $\hspace{0.3cm} p < 0$ :

$$
y_k = y_{k + 1}\\
$$

$$
\begin{align*}
p_{k+1} &= p_k + 2(x_k + 1) + 0 - 0 + 1 \\
&= p_k + 2(x_k + 1) + 1
\end{align*}
$$

**Else**:

$$
y_{k + 1} = y_k - 1 \\
$$

$$
\begin{align*}
p_{k+1} &= p_k + 2(x_k + 1) - (y_{k + 1} - y_k) + ((y_k - 1)^2 - y_k^2) + 1 \\
&= p_k + 2(x_k + 1) - (y_k - 1 - y_k) + (y_k^2 - 2y_k + 1 - y_k^2) + 1 \\
&= p_k + 2(x_k + 1) + 1 - 2y_k + 1 + 1\\
&= p_k + 2(x_k + 1) + 1 - 2y_k + 2\\
&= p_k + 2(x_k + 1) + 1 - 2(y_k - 1)\\
&= p_k + 2(x_k + 1) + 1 - 2(y_{k + 1})\\
&= p_k + 2(x_k + 1) - 2(y_{k + 1}) + 1\\
\end{align*}
$$

as $\hspace{0.3cm}x_{k + 1} = x_k + 1$, We can finally write that:

**If** $\hspace{0.3cm} p < 0$ :

$$
p_{k+1} = p_k + 2x_{k + 1} + 1
$$

**Else**:

$$
p_{k + 1} = p_k + 2x_{k + 1} - 2y_{k + 1} + 1\\
$$

---

<br/>

We consider $(0, r)$ as the **starting point**. So,

$$
\begin{align*}
p_0 &= (0 + 1)^2 + \left(r + \frac{1}{2}\right)^2 - r^2 \\
&= \left(\frac{5}{4} - r\right) \hspace{1cm}\tag{for float radius}\\
&= \left(1 - r\right) \hspace{1cm}\tag{for integer radius}
\end{align*}
$$
