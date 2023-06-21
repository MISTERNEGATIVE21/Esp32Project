from django.db import models

class randomData(models.Model):
    random1 = models.IntegerField()
    random2 = models.IntegerField()
    created_at = models.DateTimeField(auto_now_add=True)

    # def __str__(self):
    #     return f'Random Data 1: {self.random1} | Random Data 2: {self.random2}'
