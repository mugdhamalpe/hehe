import random

greetings=["Hello!", "Hi!", "Hey!", "Heyo!", "Greetings!", "Nice to see you!"]
goodbyes=["See you soon", "Goodbye", "See you later", "Farewell", "Bye!", "Take care!"]
help_responses=["How can I help you?", "How may I assist you?", "What can I do for you today?"]
problem_responses=['I\'m sorry to hear that. Can you please tell me more about the problem?', 'Let me see if I can help. What seems to be the issue?', 'I\'ll do my best to help you. What\'s the problem?']
thankyou_responses=["You are welcome", "Most welcome", "Glad to help", "Happy to help", "No problem", "It was my pleasure"]

def chatbot():
    print("Chatbot : "+random.choice(greetings))

    while True:
        user_input=input("User : ")
        if 'hello' in user_input.lower() or 'hi' in user_input.lower() or 'hey' in user_input.lower():
            print("Chatbot : "+random.choice(greetings))
        elif 'bye' in user_input.lower() or 'goodbye' in user_input.lower() or 'see you' in user_input.lower():
            print('Chatbot : '+random.choice(goodbyes))
        elif 'help' in user_input.lower() or 'support' in user_input.lower() or 'advice' in user_input.lower():
            print("Chatbot : "+random.choice(help_responses))
        elif 'problem' in user_input.lower() or 'difficulty' in user_input.lower() or 'issue' in user_input.lower():
            print("Chatbot : "+random.choice(problem_responses))
        elif 'thank you' in user_input.lower() or 'thanks' in user_input.lower() or 'thankyou' in user_input.lower():
            print("Chatbot : "+random.choice(thankyou_responses))
        else:
            print("Chatbot : Sorry, I wasn not able to understand. Do you mind rephrasing your question?")

chatbot()