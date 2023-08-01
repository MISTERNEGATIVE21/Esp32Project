from django.contrib import admin
from django.urls import path
from main import views
from main.views import esp32_data_view

urlpatterns = [
    path('', views.index, name='home'),
    path('about', views.about, name='about'),
    path('pastdatas', views.pastdatas, name='pastdatas'),
    #path('esp32-data', views.esp32_data_view, name='esp32_data'),
    path('esp32_data_view/', esp32_data_view, name='esp32_data_view')
    #path('receive-data', views.receive_data, name='receive-data')
]
