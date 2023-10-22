import turtle
import time
import random

# Cài đặt cửa sổ trò chơi
wn = turtle.Screen()
wn.title("Trò chơi Con Rắn")
wn.bgcolor("black")
wn.setup(width=600, height=600)

# Tạo đầu rắn
head = turtle.Turtle()
head.speed(0)
head.shape("square")
head.color("green")
head.penup()
head.goto(0, 0)
head.direction = "stop"

# Tạo thức ăn
food = turtle.Turtle()
food.speed(0)
food.shape("circle")
food.color("red")
food.penup()
food.goto(0, 100)

segments = []

# Hàm di chuyển
def go_up():
    if head.direction != "down":
        head.direction = "up"

def go_down():
    if head.direction != "up":
        head.direction = "down"

def go_left():
    if head.direction != "right":
        head.direction = "left"

def go_right():
    if head.direction != "left":
        head.direction = "right"

# Điều khiển bàn phím
wn.listen()
wn.onkeypress(go_up, "w")
wn.onkeypress(go_down, "s")
wn.onkeypress(go_left, "a")
wn.onkeypress(go_right, "d")

# Hàm kiểm tra va chạm
def check_collision(a, b):
    return abs(a - b) < 20

# Hàm cập nhật trạng thái trò chơi
def update():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)
    
    if head.direction == "down":
        y = head.ycor()
        head.sety(y - 20)
    
    if head.direction == "left":
        x = head.xcor()
        head.setx(x - 20)
    
    if head.direction == "right":
        x = head.xcor()
        head.setx(x + 20)
    
    # Kiểm tra va chạm với thức ăn
    if check_collision(head.xcor(), food.xcor()) and check_collision(head.ycor(), food.ycor()):
        # Di chuyển thức ăn ngẫu nhiên
        x = random.randint(-290, 290)
        y = random.randint(-290, 290)
        food.goto(x, y)

        # Tạo và thêm đoạn thân mới
        new_segment = turtle.Turtle()
        new_segment.speed(0)
        new_segment.shape("square")
        new_segment.color("green")
        new_segment.penup()
        segments.append(new_segment)

    # Di chuyển các đoạn thân của rắn
    for i in range(len(segments) - 1, 0, -1):
        x = segments[i - 1].xcor()
        y = segments[i - 1].ycor()
        segments[i].goto(x, y)

    # Di chuyển đoạn thân đầu tiên đến vị trí của đầu
    if len(segments) > 0:
        x = head.xcor()
        y = head.ycor()
        segments[0].goto(x, y)

    # Kiểm tra va chạm với đoạn thân
    for segment in segments:
        if segment != head and check_collision(head.xcor(), segment.xcor()) and check_collision(head.ycor(), segment.ycor()):
            time.sleep(1)
            head.goto(0, 0)
            head.direction = "stop"

            # Xóa đoạn thân cũ
            for segment in segments:
                segment.goto(1000, 1000)

            segments.clear()

    time.sleep(0.1)

# Vòng lặp chính của trò chơi
while True:
    wn.update()
    update()

wn.mainloop()
