<h1>Overview</h1>
    <p>This project implements a calculator application with support for basic arithmetic operations, matrix math, and probability distributions.</p>

<h2>Main Components</h2>

<h3>text.h/.cpp</h3>
<p>Contains Text class with methods to print menus and execute math operations.</p>

 <ul>
        <li><code>matrix_menu()</code> - Prints menu for matrix operations</li>
        <li><code>matrix_sum()</code> - Adds two matrices</li>
        <li><code>matrix_diff()</code> - Subtracts two matrices</li>
        <li><code>matrix_prod()</code> - Multiplies two matrices</li>
        <li><code>matrix_transpose()</code> - Transposes a matrix</li>
        <li><code>matrix_scale()</code> - Multiplies a matrix by a scalar</li>
        <li><code>matrix_det()</code> - Calculates determinant of a matrix</li>
        <li><code>basic_menu()</code> - Prints menu for basic arithmetic</li>
        <li><code>bye()</code> - Prints goodbye message</li>
</ul>

<h3>matrix.h/.cpp</h3>
<p>Contains Matrix class to represent matrices and perform operations.</p>

<ul>
        <li><code>inputMatrix()</code> - Inputs matrix values from user</li>
        <li><code>printMatrix()</code> - Prints matrix contents</li>
        <li><code>transpose()</code> - Returns transpose of matrix</li>
        <li><code>scaleMatrix()</code> - Returns matrix multiplied by scalar</li>
        <li><code>determinant_2_2()</code> - 2x2 determinant</li>
        <li><code>determinant_3_3()</code> - 3x3 determinant</li>
        <li><code>determinant_4_4()</code> - 4x4 determinant</li>
        <li><code>fill()</code> - Fills matrix from vector</li>
        <li><code>inverse_2_2()</code> - Finds inverse of 2x2 matrix</li>
        <li><code>operator+</code> - Overloaded + for matrix addition</li>
        <li><code>operator-</code> - Overloaded - for matrix subtraction</li>
        <li><code>operator|</code> - Overloaded | for matrix multiplication</li>
        <li><code>operator[]</code> - Overloaded [] for element access</li>
</ul>

<h3>crammer.h/.cpp</h3>
<p>Implements Cramer's rule for solving a system of linear equations.</p>

<ul>
        <li><code>get_ratio()</code> - Parses equation string into coefficient ratios</li>
        <li><code>is_correct()</code> - Checks format of equation</li>
        <li><code>start_crammer()</code> - Implements Cramer's rule</li>
</ul>

<h3>probSolver.h/.cpp</h3>
<p>Computes probability mass functions for various discrete distributions.</p>

<ul>
        <li><code>factorial()</code> - Computes factorial</li>
        <li><code>bernoulli()</code> - Bernoulli distribution PMF</li>
        <li><code>poisson()</code> - Poisson distribution PMF</li>
        <li><code>laplace_local()</code> - Localized Laplace distribution PMF</li>
</ul>

<h3>main.cpp</h3>
<p>Entry point and main application loop.</p>

<ul>
        <li>Sets up signal handler for keyboard interrupt</li>
        <li>Prints operation menus and reads user input</li>
        <li>Calls appropriate functions based on input</li>
        <li>Loops until the user quits</li>
</ul>

<p>The code demonstrates good practices like separating interface and implementation (text vs matrix), overloading operators, and using const correctness. Overall, it provides a useful set of math utilities in an easy-to-use application.</p>
