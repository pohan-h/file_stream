document.addEventListener('DOMContentLoaded', function() {
    const follower = document.getElementById('follower');
    
    document.addEventListener('mousemove', function(e) {
        const x = e.clientX - 10;
        const y = e.clientY - 10;

        // 當偵測到鼠標移動時，將透明度設為1
        follower.style.opacity = 0.5;
        follower.style.left = x + 'px';
        follower.style.top = y + 'px';
    });
});
