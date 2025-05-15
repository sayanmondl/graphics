## **Ellipse**

There are two focus points $F_1(x_1, y_1)$ and $F_2(x_2, y_2)$. If the distances to the two focus positions from any point $P = (x, y)$ on the ellipse are labeled $d_1$ and $d_2$ , then the general equation of an ellipse can be stated as:

$$
d_1 + d_2 = constant
$$

Expressing distances $d_1$ and $d_2$ in terms of the focal coordinates $F1 = (x_1 , y_1)$ and $F2 = (x_2 , y_2)$, we have:

$$
\sqrt{(x - x_1)^2 + (y - y_1)^2} + \sqrt{(x - x_2)^2 + (y - y_2)^2} = constant
$$

---

### **Equation**

<img src="./assets/ellipse.svg" style="border-radius:10px">

<br/>
<br/>
So, the ellipse equation can be written as:

$$
\left(\frac{x - x_c}{r_x}\right)^2 + \left(\frac{y - y_c}{r_y}\right)^2 = 1 \\
$$

for center $(0, 0)$:

$$
\left(\frac{x}{r_x}\right)^2 + \left(\frac{y}{r_y}\right)^2 = 1 \\
x^2r_y^2 + y^2r_x^2 = r_x^2r_y^2\\
x^2r_y^2 + y^2r_x^2 - r_x^2r_y^2 = 0
$$

$$
f_{ellipse}(x, y) = x^2r_y^2 + y^2r_x^2 - r_x^2r_y^2
$$

**If**

- $f_{ellipse}(x, y)$ < 0, (x, y) is inside the boundary.
- $f_{ellipse}(x, y)$ = 0, (x, y) is on the boundary.
- $f_{ellipse}(x, y)$ > 0, (x, y) is outside the boundary.

---

### **Midpoint Ellipse Algorithm**

<img src="./assets/ellipse_midpoint.svg" style="border-radius:10px; width: 400px">

<br/>
<br/>

**For region 1:**

Initial decision parameter $p1_0$:

$$
\begin{align*}
p1_0 &= f_{ellipse}\left(1, r_y - \frac{1}{2}\right) \\
&= r_y^2 + \left(r_y - \frac{1}{2}\right)^2r_x^2 - r_x^2r_y^2 \\
&= r_y^2 - r_x^2r_y + \frac{1}{4} r_x^2
\end{align*}
$$

Decision parameter at $k$:

$$
\begin{align*}
p1_k &= f_{ellipse}\left(x_k + 1, y_k - \frac{1}{2}\right) \\
&= r_y^2 (x_k + 1)^2 + r_x^2 \left( y_k - \frac{1}{2} \right)^2 - r_x^2 r_y^2
\end{align*}
$$

So, Next step, at $k+1$:

$$
\begin{align*}
p1_{k+1} &= f_{ellipse}\left(x_{k+1} + 1, y_{k+1} - \frac{1}{2}\right) \\
&= r_y^2 [(x_k + 1) + 1]^2 + r_x^2 \left( y_{k+1} - \frac{1}{2} \right)^2 - r_x^2 r_y^2
\end{align*}
$$

$$
p1_{k+1} = p1_k + 2r_y^2(x_k + 1) + r_y^2 + r_x^2 \left[ \left( y_{k+1} - \frac{1}{2} \right)^2 - \left( y_k - \frac{1}{2} \right)^2 \right]
$$

Where $y_{k+1}$ is either $y_k$ or $y_k-1$, depending upon $p1_k$.
The decision parameter increments by:

$$
\text{increment} =
\begin{cases}
2r_y^2 x_{k+1} + r_y^2, & \text{if } p1_k < 0 \\
2r_y^2 x_{k+1} + r_y^2 - 2r_x^2 y_{k+1}, & \text{if } p1_k \geq 0
\end{cases}
$$

<br/>
<br/>

**For region 2:**

Initial decision parameter $p2_0$:

$$
\begin{align*}
p2_0 &= f_{\text{ellipse}}\left(x_0 + \frac{1}{2}, y_0 - 1\right) \\
&= r_y^2 \left(x_0 + \frac{1}{2}\right)^2 + r_x^2 (y_0 - 1)^2 - r_x^2 r_y^2
\end{align*}
$$

Decision parameter at $k$:

$$
\begin{align*}
p2_k &= f_{\text{ellipse}}\left(x_k + \frac{1}{2}, y_k - 1\right) \\
&= r_y^2 \left(x_k + \frac{1}{2}\right)^2 + r_x^2 (y_k - 1)^2 - r_x^2 r_y^2
\end{align*}
$$

So, Next step, at $k+1$:

$$
\begin{align*}
p2_{k+1} &= f_{\text{ellipse}}\left(x_{k+1} + \frac{1}{2}, y_{k+1} - 1\right) \\
&= r_y^2 \left(x_{k+1} + \frac{1}{2}\right)^2 + r_x^2 \left[(y_k - 1) - 1\right]^2 - r_x^2 r_y^2 \\[1ex]
\end{align*}
$$

$$
p2_{k+1} = p2_k - 2r_x^2(y_k - 1) + r_x^2 + r_y^2 \left[ \left(x_{k+1} + \frac{1}{2} \right)^2 - \left(x_k + \frac{1}{2} \right)^2 \right]
$$
