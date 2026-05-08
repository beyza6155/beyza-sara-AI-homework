// ============================================================
// TASK 1 — Console Warmup
// ============================================================

// 1a: Change title text
document.querySelector('#main-title').textContent = "DOM Mastery 🚀";

// 1b: Log card count
const cards = document.querySelectorAll('.card');
console.log(`There are ${cards.length} cards on this page.`);

// 1c: Change box color
document.querySelector('#target-box').style.backgroundColor = "#f59e0b";


// ============================================================
// TASK 2 — Click Counter
// ============================================================

const countDisplay = document.querySelector('#count-display');
const btnInc = document.querySelector('#btn-increment');
const btnDec = document.querySelector('#btn-decrement');
const btnReset = document.querySelector('#btn-reset');

let count = 0;

function updateCountDisplay() {
    countDisplay.textContent = count;
    
    // Manage CSS classes for visual feedback
    if (count === 0) {
        countDisplay.classList.add('zero');
        countDisplay.classList.remove('high');
    } else if (count > 5) {
        countDisplay.classList.add('high');
        countDisplay.classList.remove('zero');
    } else {
        countDisplay.classList.remove('zero', 'high');
    }
}

btnInc.addEventListener('click', () => {
    count++;
    updateCountDisplay();
});

btnDec.addEventListener('click', () => {
    if (count > 0) {
        count--;
        updateCountDisplay();
    }
});

btnReset.addEventListener('click', () => {
    count = 0;
    updateCountDisplay();
});

updateCountDisplay();


// ============================================================
// TASK 3 — Dynamic List Builder
// ============================================================

const listInput = document.querySelector('#list-input');
const btnAdd = document.querySelector('#btn-add-item');
const dynamicList = document.querySelector('#dynamic-list');

btnAdd.addEventListener('click', () => {
    const text = listInput.value.trim();
    
    if (text === "") {
        listInput.focus();
        return;
    }

    // Create <li>
    const li = document.createElement('li');
    li.innerHTML = `${text} <button class="delete-btn">×</button>`;
    
    // Append to list
    dynamicList.appendChild(li);
    
    // Reset input
    listInput.value = "";
    listInput.focus();
});

// Event Delegation for Delete Buttons
dynamicList.addEventListener('click', function(event) {
    if (event.target.classList.contains('delete-btn')) {
        event.target.parentElement.remove();
    }
});


// ============================================================
// TASK 4 — Show / Hide Toggle
// ============================================================

const toggleBtn = document.querySelector('#btn-toggle');
const detailsDiv = document.querySelector('.details');

toggleBtn.addEventListener('click', () => {
    const isHidden = detailsDiv.classList.toggle('hidden');
    toggleBtn.textContent = isHidden ? "Show Details" : "Hide Details";
});


// ============================================================
// TASK 5 — Color Mixer
// ============================================================

const sliderR = document.querySelector('#slider-r');
const sliderG = document.querySelector('#slider-g');
const sliderB = document.querySelector('#slider-b');
const colorPreview = document.querySelector('#color-preview');
const hexDisplay = document.querySelector('#hex-display');

function updateColor() {
    const r = parseInt(sliderR.value);
    const g = parseInt(sliderG.value);
    const b = parseInt(sliderB.value);

    // Update labels
    document.querySelector('#val-r').textContent = r;
    document.querySelector('#val-g').textContent = g;
    document.querySelector('#val-b').textContent = b;

    // Apply color
    const rgb = `rgb(${r}, ${g}, ${b})`;
    colorPreview.style.backgroundColor = rgb;

    // Convert to Hex
    const hex = [r, g, b].map(val => 
        val.toString(16).padStart(2, '0')
    ).join('').toUpperCase();
    
    hexDisplay.textContent = `#${hex}`;
}

[sliderR, sliderG, sliderB].forEach(slider => {
    slider.addEventListener('input', updateColor);
});

updateColor();
