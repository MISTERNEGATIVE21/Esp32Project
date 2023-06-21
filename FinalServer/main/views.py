from django.shortcuts import render
from django.views import View
from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from .models import randomData
from django.http import JsonResponse
# Create your views here.

# def esp32_data_view(request):
#     if request.method == 'POST':
#         # Access and process the data sent by the ESP32
#         esp32_data = request.POST.get('data')
        
#         # Perform necessary operations based on the data received from the ESP32
#         # ...

#         # Prepare the response data
#         response_data = {
#             'status': 'success',
#             'message': 'Data received and processed successfully',
#         }

#         # Return the response to the ESP32
#         return JsonResponse(response_data)


# sensor_data = {}  # Dictionary to store sensor values

# @csrf_exempt
# def receive_data(request):
#     if request.method == 'POST':
#         value = request.POST.get('value')
#         if value:
#             sensor_data['value'] = value
#             return HttpResponse(status=200)
    
#     return HttpResponse(status=400)


# class RandomValuesView(View):
#     def post(self, request):
#         value1 = request.POST.get('random1')
#         value2 = request.POST.get('random2')
#         if value1 and value2:
#             # Do something with the received value
#             print(f"Received random value: {value1}")
#             print(f"Received random value: {value2}")
#             # You can store the value in a database or perform any other desired action here
#             return HttpResponse(status=200)
#         else:
#             return HttpResponse(status=400)
   
#     # context = {
#     #     'var' : 'Suman'
#     # }
#     return render(request,'index.html')
#     # return HttpResponse("This is HOME?Page")

def about(request):
    return render(request,'about.html')

def pastdatas(request):
    data = randomData.objects.all()
    sensor = {
    "sensor_value": data
}
    return render(request, 'pastdatas.html', sensor)

def index(request):
    
    latest_data = randomData.objects.latest('created_at')
    return render(request, 'index.html', {'latest_data': latest_data})


    

# @csrf_exempt
# def index(request):
#     #return render(request,'index.html')
#     if request.method == 'POST':
#         # Extract data from the POST request sent by the ESP32 server
#         random1 = request.POST.get('random1')
#         random2 = request.POST.get('random2')
        
#         # Create a new instance of the SensorData model
#         data = randomData(random1=random1, random2=random2)
        
#         # Save the data to the database
#         data.save()
        
#         return HttpResponse('Data received and stored successfully.')
#     else:
#         return HttpResponse('Invalid request method.')
    

def esp32_data_view(request):
    if request.method == 'POST':
        # Access and process the data sent by the ESP32
        value1 = (request.POST.get('data1'))
        value2 = (request.POST.get('data2'))
        print (value1)
        print (value2)
        esp32_data = randomData(random1=value1, random2=value2)
        esp32_data.save()
        # Save the data in the database
      #  esp32_data = randomData(value1, value2)
       
        return HttpResponse('Data received and saved successfully.')

    # Return a response for other HTTP methods (GET, etc.)
    return HttpResponse('Invalid request method.')

