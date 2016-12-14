"""Tensorflow사용을 위해 import 해줍니다."""
import tensorflow as tf 

"""머신러닝을 위해서 학습데이터와 테스트 데이터 그리고 검증 데이터를 다운받습니다."""
from tensorflow.examples.tutorials.mnist import input_data
https://codeonweb.com/entry/c1fa46e4-6cd4-42fe-8d56-36ec7826a6f1
# Dataset loading
mnist = input_data.read_data_sets("./samples/MNIST_data/", one_hot=True)

# Set up model
# 텐서는 n차원 행렬입니다.

""" x에 TensorFlow에게 계산을 시킬 떄 입력할 값입니다.
	[None, 784]형태의 부정소숫점으로 이루어진 2차원 행렬으로 표현합니다."""
x = tf.placeholder(tf.float32, [None, 784])
""" Variable은 TensorFlow의 상호작용하는 작업 그래프들간에 유지되는 변경 가능한 텐서입니다."""
""" W와 b를 0으로 채워진 텐서로 초기화 합니다. 어차피 나중에 다 학습할 것이라서 뭘로 초기화해도 상관없습니다."""
W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))
""" matmul(x, W)로 x와 W를 곱한다.
	그리고 b값을 더한다.
	마지막으로 소프트맥스를 적용합니다."""
y = tf.nn.softmax(tf.matmul(x, W) + b)

"""교차 엔트로피를 사용하는데 이것은 우리의 예측이 참값을 표현하는데 얼마나 
	비효율적인지 측정합니다.
	교차 엔트로피를 구현하기 위해 우리는 placeholder를 추가해야 합니다. """
y_ = tf.placeholder(tf.float32, [None, 10])


"""그러면 −∑y′log⁡(y)를 구현할 수 있습니다.
	y의 각 원소의 로그값을 계산하고 y_의 각 원소에 곱해준다음
	텐서의 모든 원소를 더해줍니다."""
cross_entropy = -tf.reduce_sum(y_*tf.log(y))

"""TensorFlow에게 gradient descent(경사 하강법)라는 알고리즘을 이용해서
	교차 엔트로피를 최소화 하도록 명령합니다.
	이것은 TensorFlow가 각각의 변수들을 비용을 줄이는 방향으로 약간씩 바꾸는 간단한 방법입니다."""
train_step = tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy)

# Session
""" 우리가 만든 변수들을 초기화해야합니다."""
init = tf.initialize_all_variables()

"""이제 세션에서 모델을 시작하고 변수들을 초기화하는 작업을 실행합니다. """
sess = tf.Session()
sess.run(init)

# Learning
"""1000번 학습시켜 봅니다."""
"""각 반복단꼐마다, 학습세트로부터 100개의 랜덤으로 고른 데이터들의 
	batch(일괄 처리들)을 가져옵니다. 이것을 확률적 교육이라고 합니다.
	우리의 경우 경사 하강법을 사용했으니 확률적 경사 하강법입니다. 
	그리고 placeholders를 대체하기 위한 일괄 처리 데이터에 train_step피딩을 실행합니다."""
for i in range(1000):
  batch_xs, batch_ys = mnist.train.next_batch(100)
  sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})

# Validation
""" argmax를 사용해 진짜 라벨과 우리가 만든 모델이 예측한 라벨과 비교해서 실제와 맞았는지 확인할 수 있습니다."""
correct_prediction = tf.equal(tf.argmax(y,1), tf.argmax(y_,1))

""" 얼마나 많은 비율로 맞았는지 확인하려면 부정소수점으로 casting한 후 평균값을 구합니다."""
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

# Result should be approximately 91%.
""" 테스트 데이터를 대상으로 정확도를 확인해보면 약 91.17%가 나옵니다."""
print(sess.run(accuracy, feed_dict={x: mnist.test.images, y_: mnist.test.labels}))